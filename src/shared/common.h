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

#ifndef COMMON_H_
#define COMMON_H_

// Compiler flags
#ifdef _MSC_VER
    #define NEWORLD_COMPILER_MSVC
#endif

// OS flags
#if defined _WIN32 || defined __CYGWIN__
    #define NEWORLD_TARGET_WINDOWS
    #define NEWORLD_USE_WINAPI // Windows native API
#else
    //#    define NEWORLD_TARGET_LINUX
    //#    define NEWORLD_TARGET_MACOSX
#endif

#ifdef _DEBUG
    #define NEWORLD_DEBUG // Main debug flag
#endif

#ifdef NEWORLD_DEBUG
    //    ...
#else
    #ifndef NDEBUG
        #define NDEBUG // NDEBUG flag for cassert
    #endif
#endif

#ifdef NEWORLD_USE_WINAPI
    #define WIN32_LEAN_AND_MEAN
    #include <Windows.h> // Windows API
#else
    //#    include <pthread.h> // Or <thread> <mutex>
#endif

#include <cassert>

#if (-1)>>1 == -1
    #define NEWORLD_COMPILER_RSHIFT_ARITH // Arithmetic shift right
#endif

// NWAPICALL
#ifdef NEWORLD_COMPILER_MSVC
    #define NWAPICALL __cdecl
#elif defined(__i386__) || defined(__i386)
    #define NWAPICALL __attribute__((__cdecl__))
#else
    #define NWAPICALL
#endif

// NWAPIEXPORT
#ifdef NEWORLD_TARGET_WINDOWS
    #ifdef NEWORLD_COMPILER_MSVC
        #define NWAPIEXPORT __declspec(dllexport)
    #else
        #define NWAPIEXPORT __attribute__((dllexport))
    #endif
#else
    #define NWAPIEXPORT __attribute__((visibility("default")))
#endif

constexpr unsigned int NEWorldVersion = 41u;
constexpr unsigned int ReleaseVersion = (NEWorldVersion << 16) + 2;
constexpr const char* CopyrightString = R"(
NEWorld  Copyright (C) 2016  NEWorld Team
This program comes with ABSOLUTELY NO WARRANTY.
This is free software, and you are welcome to redistribute it under certain conditions.
For details see "LICENSE".
)";

#if defined(NEWORLD_TARGET_WINDOWS)
    constexpr const char* DLLSuffix = "dll";
#elif defined(NEWORLD_TARGET_MACOSX)
    constexpr const char* DLLSuffix = "dylib";
#else
    constexpr const char* DLLSuffix = "so";
#endif

#endif // !COMMON_H_
