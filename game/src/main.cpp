/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

-- Copyright (c) 2020-2024 Jeffery Myers
--
--This software is provided "as-is", without any express or implied warranty. In no event 
--will the authors be held liable for any damages arising from the use of this software.

--Permission is granted to anyone to use this software for any purpose, including commercial 
--applications, and to alter it and redistribute it freely, subject to the following restrictions:

--  1. The origin of this software must not be misrepresented; you must not claim that you 
--  wrote the original software. If you use this software in a product, an acknowledgment 
--  in the product documentation would be appreciated but is not required.
--
--  2. Altered source versions must be plainly marked as such, and must not be misrepresented
--  as being the original software.
--
--  3. This notice may not be removed or altered from any source distribution.

*/

#include "raylib.h"
#include "raymath.h"

#include "game.h"   // an external header in this project
#include "lib.h"	// an external header in the static lib project
#include "Game.hpp";
#include <iostream>
#include "include/json.hpp"
//TEST
#include "Gui.hpp"
#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"

enum GameState {TITLE, MAIN_GAME, PAUSED, END};

int main()
{
	const int screenWidth = 1500;
	const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "Caberet Madness");
    SetTargetFPS(60);
    GameState initialState = TITLE; 
    Game game;

    while (!WindowShouldClose())
    {
        switch (initialState)
        {
        case TITLE:
            if (IsKeyPressed(KEY_ENTER))
            {
                initialState = MAIN_GAME;
                //game.m_gameTimer.setTotalTime(game.m_timePerNight);
                game.m_gameTimer.setTotalTime(30.0f);
                game.m_gameTimer.startTimer();
            }
            break;
        case MAIN_GAME:
            if (game.m_gameTimer.m_hasTimerRunOut)
            {
                initialState = END;
            }
        }
        BeginDrawing();
        ClearBackground(BLACK);
        switch (initialState)
        {
        case TITLE:
            GUI::showTitleScreen();
            break;
        case MAIN_GAME:
            game.playGame();
            break;
        case END:
            GUI::showEndScreen(game.m_hostessManager);
            break;
        }
        
        
        EndDrawing();

    }

    CloseWindow();

    return 0;
}