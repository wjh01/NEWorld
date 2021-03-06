/*
* NEWorld: A free game with similar rules to Minecraft.
* Copyright (C) 2016 NEWorld Team
*
* This file is part of NEWorld.
* NEWorld is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* NEWorld is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with NEWorld.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "shared.h"

int32_t RockID;

void registerBlocks()
{
    NWblocktype rock;
    rock.blockname = "Rock";
    rock.solid = 1;
    rock.translucent = 0;
    rock.opaque = 1;
    rock.explodePower = 0;
    rock.hardness = 2;
    RockID = nwRegisterBlock(&rock);
}

NWplugindata* getInfo(bool client)
{
    auto plugin = new NWplugindata();
    plugin->pluginName = "NEWorld";
    plugin->authorName = "INFINIDEAS";
    plugin->internalName = client ? "infinideas.neworld.client" : "infinideas.neworld.server";
    plugin->isClientPlugin = client;
    return plugin;
}

void sharedInit()
{
    registerBlocks();
}
