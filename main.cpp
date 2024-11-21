#include "raylib.h"
#include "Inventory.h"
#include "GameInit.h"
#include <iostream>

using namespace std;

void Start();
void Update();
void Draw();
void End();

Font ft;
GameInit gameManage;
Inventory myInvotory = Inventory();

int main()
{
    Start();

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    End();
    return 0;
}


void Start()
{
    
    InitWindow(1200, 800, "Inventory RPG");
    SetTargetFPS(60);
    ft = LoadFont("resources/fonts/jupiter_crash.png");

    gameManage.Init();

    myInvotory.Start();

    myInvotory.AddToInventory(gameManage.broadSword);
    myInvotory.AddToInventory(gameManage.cactusSword);
    myInvotory.AddToInventory(gameManage.meteorStrike);
    myInvotory.AddToInventory(gameManage.summonSatan);
    myInvotory.AddToInventory(gameManage.poseidonStaff);
    myInvotory.AddToInventory(gameManage.bread);
    myInvotory.AddToInventory(gameManage.honey);
    myInvotory.AddToInventory(gameManage.chainedChesplate);
    myInvotory.AddToInventory(gameManage.spartaHelmet);
}


void Update()
{
    //add item in inventory
    if (IsMouseButtonReleased(MOUSE_BUTTON_MIDDLE))
    {
        myInvotory.AddToInventory(gameManage.cactusSword);
        myInvotory.AddToInventory(gameManage.chicken);
        myInvotory.AddToInventory(gameManage.chanterelles);
        myInvotory.AddToInventory(gameManage.herbsBundle);
        myInvotory.AddToInventory(gameManage.bokChoy);
    }


    for (int x = 0; x < myInvotory.actualInvotory.size(); x++)
    {
        myInvotory.Update(x, ft);
    }
}

void Draw()
{
    BeginDrawing();

    ClearBackground(DARKBROWN);

    DrawTextEx(ft, "Middle click for search", Vector2{ 925, 525 }, 25, 5, YELLOW);
    DrawTextEx(ft, "lot of items", Vector2{ 925, 550 }, 25, 5, YELLOW);
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            myInvotory.Draw(x, y, ft);
        }
    }
    for (int x = 0; x < myInvotory.actualInvotory.size(); x++)
    {
        myInvotory.DrawItem(x, ft);
    }
    
    myInvotory.ActualiseUnvotory();

    EndDrawing();
}


void End()
{
    CloseWindow();
}