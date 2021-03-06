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

#ifndef GAMEVIEW_H_
#define GAMEVIEW_H_

#include <thread>
#include <uilib.h>
#include "vec3.h"
#include "renderer.h"

#include <world.h>
#include <logger.h>
#include <pluginapi.h>
#include <blockmanager.h>
#include <pluginmanager.h>
#include "../server/worldserver.h"
#include "worldclient.h"
#include "texture.h"
#include "player.h"
#include "network.h"

class GameScene : public UI::Controls::GLContext
{
public:
    GameScene(UI::Core::Window*, BlockManager& bm, PluginManager& pm);

    ~GameScene()
    {
        m_plugins.unloadPlugins();
        m_connection.disconnect();
        if (m_localServerThread.joinable()) m_localServerThread.join();
    }
    void doRender();
    void onResize(size_t w, size_t h) override;
    void init(UI::Core::Window* win);
    void onKey(int key);

private:
    int windowWidth = 852, windowHeight = 480;

    // Texture test
    Texture m_texture;
    // Blocks
    BlockManager& m_blocks;
    // Loaded plugins
    PluginManager& m_plugins;
    // World
    WorldClient m_world;
    // Player test
    Player m_player;
    // Network connection
    Connection m_connection;
    // Local server thread
    std::thread m_localServerThread;
};

#endif // !GAMEVIEW_H_
