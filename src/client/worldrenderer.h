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

#ifndef WORLDRENDERER_H_
#define WORLDRENDERER_H_

#include <world.h>
#include "chunkrenderer.h"

class WorldRenderer : public World
{
public:
    WorldRenderer(const std::string& name, PluginManager& plugins, BlockManager& blocks)
        : World(name, plugins, blocks)
    {
    }

    WorldRenderer(World&& world) : World(std::move(world))
    {
    }

    Chunk* addChunk(const Vec3i& chunkPos) override;

    // Build/Destroy VBO
    void renderUpdate();

    // Render all chunks
    void render() const
    {
        for (size_t i = 0; i < m_chunkCount; i++)
        {
            reinterpret_cast<ChunkRenderer*>(m_chunks[i])->render();
        }
    }
};

#endif // !WORLDRENDERER_H_
