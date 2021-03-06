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

#ifndef NETWORKSTRUCTURES_H_
#define NETWORKSTRUCTURES_H_

#include <string>
#include <cstring>
#include <cstdint>
#include "packet.h"
#include "identifier.h"

class NetworkStructure
{
public:
    virtual void process() = 0;

    virtual ~NetworkStructure()
    {
    }

    virtual Packet makePacket() = 0;
};

class LoginPacket :public NetworkStructure
{
public:
    LoginPacket(std::string username, std::string password, uint16_t version)
        : m_username(username), m_password(password), m_version(version)
    {
    }

    Packet makePacket() override
    {
        Packet p;
        p.identifier = Identifier::Login;
        p.length = m_username.length() + m_password.length() + sizeof(uint16_t) + 2; //username+password+�汾��+����\0
        p.data = std::unique_ptr<char[]>(new char[p.length]);
        strcpy(p.data.get(), m_username.c_str());
        strcpy(p.data.get() + m_username.length() + 1, m_password.c_str());
        memcpy(p.data.get() + m_username.length() + m_password.length() + 2, &m_version, sizeof(uint16_t));
        return p;
    }

    void process() override;

private:
    std::string m_username;
    std::string m_password;
    uint16_t m_version;
};

class ChatPacket : public NetworkStructure
{
public:
    ChatPacket(std::string userSend, std::string content)
        : m_userSend(userSend), m_content(content)
    {
    }

    Packet makePacket() override
    {
        Packet p;
        p.identifier = Identifier::Chat;
        p.length = 0;
        //        p.data = std::unique_ptr<char[]>(new char[p.length]);
        return p;
    }

    void process() override;


private:
    std::string m_userSend;
    std::string m_content;
};

#endif // !NETWORKSTRUCTURES_H_
