#include "Inventory.h"
Inventory::Inventory()
{

}
void Inventory::Start()
{
	foreGround = LoadTexture("resources/Icone/BG_Item.png");
	backGround = LoadTexture("resources/Icone/BG_Description.png");
}

void Inventory::Update(int x, int y, Font ft)
{

	Rectangle rec{ (int)(100 * x), (int)(100 * y), 100, 100 };
	if (CheckCollisionPointRec(GetMousePosition(), rec))
	{
		if (actualInvotory[y][x] != nullptr)
		{
			//DrawTextEx(ft, actualInvotory[y][x]->GetItemStatistique().c_str(), Vector2{ 950, 5 }, 20, 5, WHITE);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && use == true)
			{
				if (actualInvotory[y][x]->GetFood() != 0)
				{
					life += actualInvotory[y][x]->GetFood();
					if (life > maxLife) 
					{
						life = maxLife;
					}
					if (actualInvotory[y][x]->actualItemStackable > 1)
					{
						actualInvotory[y][x]->actualItemStackable -= 1;
						use = false;
					}
					else
					{
						actualInvotory[y][x] = nullptr;
					}
				}
				else if (actualInvotory[y][x]->GetLearnSpeel() != 0)
				{
					if (actualInvotory[y][x]->actualItemStackable > 1)
					{
						actualInvotory[y][x]->actualItemStackable -= 1;
						use = false;
					}
					else
					{
						actualInvotory[y][x] = nullptr;
					}
				}
				else if (actualInvotory[y][x]->GetArmor() != 0 )
				{
					actualInvotory[y][x]->SetEquip();
					if (actualInvotory[y][x]->GetEquip() == true)
					{
						armorValue += actualInvotory[y][x]->GetArmor();
					}
					else if (actualInvotory[y][x]->GetEquip() == false)
					{
						armorValue -= actualInvotory[y][x]->GetArmor();
					}
					use = false;
				}
			}
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && use == false)
			{
				use = true;
			}
			if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && press == true)
			{
				money += actualInvotory[y][x]->itemPrice;
				if (actualInvotory[y][x]->actualItemStackable > 1) 
				{
					actualInvotory[y][x]->actualItemStackable -= 1;
					press = false;
				}
				else 
				{
					actualInvotory[y][x] = nullptr;
				}
			}
			if (IsMouseButtonReleased(MOUSE_BUTTON_RIGHT) && press == false)
			{
					press = true;
			}
		}

	}
}

void Inventory::Draw(int x, int y, Font ft)
{
	Rectangle rec{ (int)(100 * x), (int)(100 * y), 100, 100 };
	Vector2 origin{ 0, 0 };
	if (x <= 18)
	{
		DrawTexturePro(foreGround, Rectangle{ 0, 0, 128, 128 }, rec, origin, 0.0f, WHITE);
	}
	else
	{
		DrawTexturePro(backGround, Rectangle{ 0, 0, 128, 128 }, rec, origin, 0.0f, WHITE);
	}

	if (CheckCollisionPointRec(GetMousePosition(), rec))
	{
		if (actualInvotory[y][x] != nullptr)
		{
			DrawTextEx(ft, actualInvotory[y][x]->GetItemStatistique().c_str(), Vector2{ 925, 5 }, 25, 5, WHITE);
			if (actualInvotory[y][x]->GetFood() != 0) 
			{
				DrawTextEx(ft, "Left click for comsum", Vector2{ 925, 475 }, 25, 5, YELLOW);
			}
			else if (actualInvotory[y][x]->GetLearnSpeel() != 0)
			{
				DrawTextEx(ft, "Left click for", Vector2{ 925, 450 }, 25, 5, YELLOW);
				DrawTextEx(ft, "learn spell", Vector2{ 925, 475 }, 25, 5, YELLOW);
			}
			else if (actualInvotory[y][x]->GetArmor() != 0 && actualInvotory[y][x]->GetEquip() == false)
			{
				DrawTextEx(ft, "Left click for equip", Vector2{ 925, 475 }, 25, 5, YELLOW);
			}
			else if (actualInvotory[y][x]->GetArmor() != 0 && actualInvotory[y][x]->GetEquip() == true)
			{
				DrawTextEx(ft, "Left click for unequip", Vector2{ 925, 475 }, 25, 5, YELLOW);
			}
			DrawTextEx(ft, "Right click for sell", Vector2{ 925, 500 }, 25, 5, YELLOW);
		}
	}

	if (actualInvotory[y][x] != nullptr) 
	{
		DrawTexturePro(actualInvotory[y][x]->itemSprite, Rectangle{0, 0, 400, 400}, rec, origin, 0.0f, WHITE);
	}

	DrawTextEx(ft, TextFormat("Armor : %01i ", armorValue), Vector2{ 925, 700 }, 25, 5, LIGHTGRAY);
	DrawTextEx(ft, TextFormat("Actual Hp : %01i/%01i", life, maxLife), Vector2{ 925, 725 }, 25, 5, PINK);
	DrawTextEx(ft, TextFormat("Actual money : %01i ", money, "PO"), Vector2{925, 750}, 25, 5, YELLOW);
}