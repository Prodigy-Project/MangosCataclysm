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

#include <sys/types.h>
#include "VMapFactory.h"
#include "VMapManager2.h"

using namespace G3D;

namespace VMAP
{
    void VMapFactory::chompAndTrim(std::string& str)
    {
        while (str.length() > 0)
        {
            char lc = str[str.length() - 1];
            if (lc == '\r' || lc == '\n' || lc == ' ' || lc == '"' || lc == '\'')
            {
                str = str.substr(0, str.length() - 1);
            }
            else
            {
                break;
            }
        }
        while (str.length() > 0)
        {
            char lc = str[0];
            if (lc == ' ' || lc == '"' || lc == '\'')
            {
                str = str.substr(1, str.length() - 1);
            }
            else
            {
                break;
            }
        }
    }

    IVMapManager* gVMapManager = 0;
    Table<unsigned int , bool>* iIgnoreSpellIds = 0;

    //===============================================
    // result false, if no more id are found

    bool VMapFactory::getNextId(const std::string& pString, unsigned int& pStartPos, unsigned int& pId)
    {
        bool result = false;
        unsigned int i;
        for (i = pStartPos; i < pString.size(); ++i)
        {
            if (pString[i] == ',')
            {
                break;
            }
        }
        if (i > pStartPos)
        {
            std::string idString = pString.substr(pStartPos, i - pStartPos);
            pStartPos = i + 1;
            chompAndTrim(idString);
            pId = atoi(idString.c_str());
            result = true;
        }
        return(result);
    }

    //===============================================
    /**
    parameter: String of map ids. Delimiter = ","
    */

    void VMapFactory::preventSpellsFromBeingTestedForLoS(const char* pSpellIdString)
    {
        if (!iIgnoreSpellIds)
        {
            iIgnoreSpellIds = new Table<unsigned int , bool>();
        }
        if (pSpellIdString != NULL)
        {
            unsigned int pos = 0;
            unsigned int id;
            std::string confString(pSpellIdString);
            chompAndTrim(confString);
            while (getNextId(confString, pos, id))
            {
                iIgnoreSpellIds->set(id, true);
            }
        }
    }

    //===============================================

    bool VMapFactory::checkSpellForLoS(unsigned int pSpellId)
    {
        return(!iIgnoreSpellIds->containsKey(pSpellId));
    }

    //===============================================
    // just return the instance
    IVMapManager* VMapFactory::createOrGetVMapManager()
    {
        if (gVMapManager == 0)
        {
            gVMapManager = new VMapManager2();               // should be taken from config ... Please change if you like :-)
        }
        return gVMapManager;
    }

    //===============================================
    // delete all internal data structures
    void VMapFactory::clear()
    {
        delete iIgnoreSpellIds;
        delete gVMapManager;

        iIgnoreSpellIds = NULL;
        gVMapManager = NULL;
    }
}
