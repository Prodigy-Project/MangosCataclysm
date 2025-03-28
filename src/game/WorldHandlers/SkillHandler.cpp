/**
 * MaNGOS is a full featured server for World of Warcraft, supporting
 * the following clients: 1.12.x, 2.4.3, 3.3.5a, 4.3.4a and 5.4.8
 *
 * Copyright (C) 2005-2025 MaNGOS <https://www.getmangos.eu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * World of Warcraft, and all World of Warcraft or Warcraft art, images,
 * and lore are copyrighted by Blizzard Entertainment, Inc.
 */

#include "Common.h"
#include "Database/DatabaseEnv.h"
#include "DBCStores.h"
#include "Opcodes.h"
#include "Log.h"
#include "Player.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "UpdateMask.h"

void WorldSession::HandleLearnTalentOpcode(WorldPacket& recv_data)
{
    DEBUG_LOG("CMSG_LEARN_PREVIEW_TALENTS");

    uint32 talent_id, requested_rank;
    recv_data >> talent_id >> requested_rank;

    if (_player->LearnTalent(talent_id, requested_rank))
    {
        _player->SendTalentsInfoData(false);
    }
    else
        sLog.outError("WorldSession::HandleLearnTalentOpcode: learn talent %u rank %u failed for %s (account %u)", talent_id, requested_rank, GetPlayerName(), GetAccountId());

    // if player has a pet, update owner talent auras
    if (_player->GetPet())
    {
        _player->GetPet()->CastOwnerTalentAuras();
    }
}

void WorldSession::HandleLearnPreviewTalents(WorldPacket& recvPacket)
{
    DEBUG_LOG("CMSG_LEARN_PREVIEW_TALENTS");

    int32 tabPage;
    uint32 talentsCount;
    recvPacket >> tabPage;    // talent tree

    // prevent cheating (selecting new tree with points already in another)
    if (tabPage >= 0)   // -1 if player already has specialization
    {
        if (TalentTabEntry const* talentTabEntry = sTalentTabStore.LookupEntry(_player->GetPrimaryTalentTree(_player->GetActiveSpec())))
        {
            if (talentTabEntry->tabpage != tabPage)
            {
                recvPacket.rfinish();
                sLog.outError("WorldSession::HandleLearnPreviewTalents: tabPage != talent tabPage for %s (account %u)", GetPlayerName(), GetAccountId());
                return;
            }
        }
    }

    recvPacket >> talentsCount;

    uint32 talentId, talentRank;

    for (uint32 i = 0; i < talentsCount; ++i)
    {
        recvPacket >> talentId >> talentRank;

        if (!_player->LearnTalent(talentId, talentRank))
        {
            recvPacket.rfinish();
            sLog.outError("WorldSession::HandleLearnPreviewTalents: learn talent %u rank %u tab %u failed for %s (account %u)", talentId, talentRank, tabPage, GetPlayerName(), GetAccountId());
            break;
        }
    }

    _player->SendTalentsInfoData(false);

    // if player has a pet, update owner talent auras
    if (_player->GetPet())
    {
        _player->GetPet()->CastOwnerTalentAuras();
    }
}

void WorldSession::HandleTalentWipeConfirmOpcode(WorldPacket& recv_data)
{
    DETAIL_LOG("MSG_TALENT_WIPE_CONFIRM");
    ObjectGuid guid;
    recv_data >> guid;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_TRAINER);
    if (!unit)
    {
        DEBUG_LOG("WORLD: HandleTalentWipeConfirmOpcode - %s not found or you can't interact with him.", guid.GetString().c_str());
        return;
    }

    if (!unit->CanTrainAndResetTalentsOf(_player))
    {
        return;
    }

    if (!(_player->resetTalents()))
    {
        WorldPacket data(MSG_TALENT_WIPE_CONFIRM, 8 + 4);   // you have not any talent
        data << uint64(0);
        data << uint32(0);
        SendPacket(&data);
        return;
    }

    _player->SendTalentsInfoData(false);
    unit->CastSpell(_player, 14867, true);                  // spell: "Untalent Visual Effect"
    if (_player->GetPet())
    {
        _player->GetPet()->CastOwnerTalentAuras();
    }
}

void WorldSession::HandleUnlearnSkillOpcode(WorldPacket& recv_data)
{
    uint32 skill_id;
    recv_data >> skill_id;
    GetPlayer()->SetSkill(skill_id, 0, 0);
}
