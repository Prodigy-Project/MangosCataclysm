﻿/**
 * ScriptDev3 is an extension for mangos providing enhanced features for
 * area triggers, creatures, game objects, instances, items, and spells beyond
 * the default database scripting in mangos.
 *
 * Copyright (C) 2006-2013 ScriptDev2 <http://www.scriptdev2.com/>
 * Copyright (C) 2014-2025 MaNGOS <https://www.getmangos.eu>
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

#ifndef DEF_ICECROWN_CITADEL_H
#define DEF_ICECROWN_CITADEL_H

enum
{
    MAX_ENCOUNTER                   = 12,

    TYPE_MARROWGAR                  = 0,
    TYPE_LADY_DEATHWHISPER          = 1,
    TYPE_GUNSHIP_BATTLE             = 2,
    TYPE_DEATHBRINGER_SAURFANG      = 3,
    TYPE_FESTERGUT                  = 4,
    TYPE_ROTFACE                    = 5,
    TYPE_PROFESSOR_PUTRICIDE        = 6,
    TYPE_BLOOD_PRINCE_COUNCIL       = 7,
    TYPE_QUEEN_LANATHEL             = 8,
    TYPE_VALITHRIA                  = 9,
    TYPE_SINDRAGOSA                 = 10,
    TYPE_LICH_KING                  = 11,

    TYPE_DATA_AREATRIGGERS          = MAX_ENCOUNTER,
    TYPE_DO_PREPARE_PROF_DOOR       = MAX_ENCOUNTER + 1,
    TYPE_DATA_IS_HEROIC             = MAX_ENCOUNTER + 2,
    TYPE_DATA_IS_25MAN              = MAX_ENCOUNTER + 3,
    TYPE_DO_SUMMON_CULTIST_WAVE     = MAX_ENCOUNTER + 4,

    // NPC entries
    NPC_LORD_MARROWGAR              = 36612,
    NPC_LADY_DEATHWHISPER           = 36855,
    NPC_DEATHBRINGER_SAURFANG       = 37813,
    NPC_FESTERGUT                   = 36626,
    NPC_ROTFACE                     = 36627,
    NPC_PROFESSOR_PUTRICIDE         = 36678,
    NPC_TALDARAM                    = 37973,
    NPC_VALANAR                     = 37970,
    NPC_KELESETH                    = 37972,
    NPC_QUEEN_LANATHEL              = 37955,
    NPC_VALITHRIA                   = 36789,
    NPC_SINDRAGOSA                  = 36853,
    NPC_LICH_KING                   = 36597,

    // boss-related and other NPCs
    NPC_DEATHWHISPER_SPAWN_STALKER  = 37947,
    NPC_DEATHWHISPER_CONTROLLER     = 37948,
    NPC_OVERLORD_SAURFANG           = 37187,
    NPC_KORKRON_REAVER              = 37920,
    NPC_MURADIN_BRONZEBEARD         = 37200,        // Saurfang's encounter and at the instance entrance
    NPC_SKYBREAKER_MARINE           = 37380,
    NPC_ALLIANCE_MARINE             = 37830,
    NPC_BLOOD_ORB_CONTROL           = 38008,
    NPC_LANATHEL_INTRO              = 38004,
    NPC_VALITHRIA_QUEST             = 38589,
    NPC_VALITHRIA_COMBAT_TRIGGER    = 38752,
    NPC_MURADIN                     = 36948,        // Gunship Battle's encounter(?)
    NPC_TIRION                      = 38995,
    NPC_MENETHIL                    = 38579,
    NPC_FROSTMOURNE_TRIGGER         = 38584,
    NPC_FROSTMOURNE_HOLDER          = 27880,
    NPC_STINKY                      = 37025,
    NPC_PRECIOUS                    = 37217,
    NPC_PUDDLE_STALKER              = 37013,        // related to Festergut and Rotface
    NPC_RIMEFANG                    = 37533,
    NPC_SPINESTALKER                = 37534,
    NPC_CULT_ADHERENT               = 37949,
    NPC_CULT_FANATIC                = 37890,

    // GameObjects entries
    GO_ICEWALL_1                    = 201911,
    GO_ICEWALL_2                    = 201910,
    GO_MARROWGAR_DOOR               = 201857,       // Marrowgar combat door

    GO_ORATORY_DOOR                 = 201563,
    GO_DEATHWHISPER_ELEVATOR        = 202220,

    GO_SAURFANG_DOOR                = 201825,

    GO_GREEN_PLAGUE                 = 201370,       // Rotface combat door
    GO_ORANGE_PLAGUE                = 201371,       // Festergut combat door
    GO_SCIENTIST_DOOR               = 201372,       // Putricide combat door
    GO_SCIENTIST_DOOR_COLLISION     = 201612,       // Putricide pathway doors
    GO_SCIENTIST_DOOR_ORANGE        = 201613,
    GO_SCIENTIST_DOOR_GREEN         = 201614,
    GO_GREEN_VALVE                  = 201615,       // Valves used to release the Gas / Oozes in order to open the pathway to Putricide - triggers event 23426
    GO_ORANGE_VALVE                 = 201616,       // triggers event 23438
    GO_ORANGE_TUBE                  = 201617,
    GO_GREEN_TUBE                   = 201618,

    // GO_BLOODWING_DOOR             = 201920,       // not used
    GO_CRIMSON_HALL_DOOR            = 201376,       // Council combat door
    GO_COUNCIL_DOOR_1               = 201377,
    GO_COUNCIL_DOOR_2               = 201378,
    GO_BLOODPRINCE_DOOR             = 201746,       // Lanathel combat door
    GO_ICECROWN_GRATE               = 201755,       // Lanathel trap door

    // GO_FROSTWING_DOOR             = 201919,       // not used
    GO_GREEN_DRAGON_ENTRANCE        = 201375,       // Valithria combat door
    GO_GREEN_DRAGON_EXIT            = 201374,
    GO_VALITHRIA_DOOR_1             = 201381,       // Valithria event doors
    GO_VALITHRIA_DOOR_2             = 201382,
    GO_VALITHRIA_DOOR_3             = 201383,
    GO_VALITHRIA_DOOR_4             = 201380,
    GO_SINDRAGOSA_SHORTCUT_ENTRANCE = 201369,       // Shortcut doors are opened only after the trash before Sindragosa is cleared
    GO_SINDRAGOSA_SHORTCUT_EXIT     = 201379,
    GO_SINDRAGOSA_ENTRANCE          = 201373,

    GO_FROZENTRONE_TRANSPORTER      = 202223,
    GO_ICESHARD_1                   = 202142,
    GO_ICESHARD_2                   = 202141,
    GO_ICESHARD_3                   = 202143,
    GO_ICESHARD_4                   = 202144,
    GO_FROSTY_WIND                  = 202188,
    GO_FROSTY_EDGE                  = 202189,
    GO_SNOW_EDGE                    = 202190,
    GO_ARTHAS_PLATFORM              = 202161,
    GO_ARTHAS_PRECIPICE             = 202078,

    GO_PLAGUE_SIGIL                 = 202182,       // Possible used after each wing is cleared
    GO_FROSTWING_SIGIL              = 202181,
    GO_BLOODWING_SIGIL              = 202183,

    // Loot chests
    GO_SAURFANG_CACHE               = 202239,
    GO_SAURFANG_CACHE_25            = 202240,
    GO_SAURFANG_CACHE_10_H          = 202238,
    GO_SAURFANG_CACHE_25_H          = 202241,

    GO_GUNSHIP_ARMORY_A             = 201872,
    GO_GUNSHIP_ARMORY_A_25          = 201873,
    GO_GUNSHIP_ARMORY_A_10H         = 201874,
    GO_GUNSHIP_ARMORY_A_25H         = 201875,

    GO_GUNSHIP_ARMORY_H             = 202177,
    GO_GUNSHIP_ARMORY_H_25          = 202178,
    GO_GUNSHIP_ARMORY_H_10H         = 202179,
    GO_GUNSHIP_ARMORY_H_25H         = 202180,

    GO_DREAMWALKER_CACHE            = 201959,
    GO_DREAMWALKER_CACHE_25         = 202339,
    GO_DREAMWALKER_CACHE_10_H       = 202338,
    GO_DREAMWALKER_CACHE_25_H       = 202340,

    // Area triggers
    AREATRIGGER_MARROWGAR_INTRO     = 5732,
    AREATRIGGER_DEATHWHISPER_INTRO  = 5709,
    AREATRIGGER_SINDRAGOSA_PLATFORM = 5604,

    // Achievement criterias
    ACHIEV_CRIT_BONED_10N                  = 12775,     // Lord Marrowgar, achievs 4534, 4610
    ACHIEV_CRIT_BONED_25N                  = 12962,
    ACHIEV_CRIT_BONED_10H                  = 13393,
    ACHIEV_CRIT_BONED_25H                  = 13394,

    ACHIEV_CRIT_HOUSE_10N                  = 12776,     // Lady Deathwhisper, achievs 4535, 4611
    ACHIEV_CRIT_HOUSE_25N                  = 12997,
    ACHIEV_CRIT_HOUSE_10H                  = 12995,
    ACHIEV_CRIT_HOUSE_25H                  = 12998,

    ACHIEV_CRIT_IM_ON_A_BOAT_10N           = 12777,     // Gunship Battle, achievs 4536, 4612
    ACHIEV_CRIT_IM_ON_A_BOAT_25N           = 13080,
    ACHIEV_CRIT_IM_ON_A_BOAT_10H           = 13079,
    ACHIEV_CRIT_IM_ON_A_BOAT_25H           = 13081,

    ACHIEV_CRIT_MADE_A_MESS_10N            = 12778,     // Deathbringer Saurfang, achievs 4537, 4613
    ACHIEV_CRIT_MADE_A_MESS_25N            = 13036,
    ACHIEV_CRIT_MADE_A_MESS_10H            = 13035,
    ACHIEV_CRIT_MADE_A_MESS_25H            = 13037,

    ACHIEV_CRIT_FLU_SHOT_SHORTAGE_10N      = 12977,     // Festergut, achievs 4615, 4577
    ACHIEV_CRIT_FLU_SHOT_SHORTAGE_25N      = 12982,
    ACHIEV_CRIT_FLU_SHOT_SHORTAGE_10H      = 12986,
    ACHIEV_CRIT_FLU_SHOT_SHORTAGE_25H      = 12967,

    ACHIEV_CRIT_DANCES_WITH_OOZES_10N      = 12984,     // Rotface, achievs 4538, 4614
    ACHIEV_CRIT_DANCES_WITH_OOZES_25N      = 12966,
    ACHIEV_CRIT_DANCES_WITH_OOZES_10H      = 12985,
    ACHIEV_CRIT_DANCES_WITH_OOZES_25H      = 12983,

    ACHIEV_CRIT_NAUSEA_10N                 = 12987,     // Professor Putricide, achievs 4578, 4616
    ACHIEV_CRIT_NAUSEA_25N                 = 12968,
    ACHIEV_CRIT_NAUSEA_10H                 = 12988,
    ACHIEV_CRIT_NAUSEA_25H                 = 12981,

    ACHIEV_CRIT_ORB_WHISPERER_10N          = 13033,     // Blood Prince Council, achievs 4582, 4617
    ACHIEV_CRIT_ORB_WHISPERER_25N          = 12969,
    ACHIEV_CRIT_ORB_WHISPERER_10H          = 13034,
    ACHIEV_CRIT_ORB_WHISPERER_25H          = 13032,

    ACHIEV_CRIT_ONCE_BITTEN_TWICE_SHY_10N  = 12780,     // Blood-Queen Lana'thel, achievs 4539, 4618
    ACHIEV_CRIT_ONCE_BITTEN_TWICE_SHY_25N  = 13012,
    ACHIEV_CRIT_ONCE_BITTEN_TWICE_SHY_10V  = 13011,
    ACHIEV_CRIT_ONCE_BITTEN_TWICE_SHY_25V  = 13013,

    ACHIEV_CRIT_PORTAL_JOCKEY_10N          = 12978,    // Valithria, achievs 4579, 4619
    ACHIEV_CRIT_PORTAL_JOCKEY_25N          = 12971,
    ACHIEV_CRIT_PORTAL_JOCKEY_10H          = 12979,
    ACHIEV_CRIT_PORTAL_JOCKEY_25H          = 12980,

    ACHIEV_CRIT_ALL_YOU_CAN_EAT_10N        = 12822,    // Sindragosa, achievs 4580, 4620
    ACHIEV_CRIT_ALL_YOU_CAN_EAT_25N        = 12972,
    ACHIEV_CRIT_ALL_YOU_CAN_EAT_10V        = 12996,
    ACHIEV_CRIT_ALL_YOU_CAN_EAT_25V        = 12989,

    ACHIEV_CRIT_WAITING_A_LONG_TIME_10N    = 13246,    // Lich King, achievs 4601, 4621
    ACHIEV_CRIT_WAITING_A_LONG_TIME_25N    = 13244,
    ACHIEV_CRIT_WAITING_A_LONG_TIME_10H    = 13247,
    ACHIEV_CRIT_WAITING_A_LONG_TIME_25H    = 13245,
};

#endif
