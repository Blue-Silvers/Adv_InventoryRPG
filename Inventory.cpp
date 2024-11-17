#include "Inventory.h"
Inventory::Inventory()
{

}

void Inventory::AddToInventory(Item* newItem)
{
	actualInvotory.push_back(newItem);
}

void Inventory::RemoveFromInventory(unsigned int itemIndex)
{
	std::vector<Item*>::iterator i;
	i = actualInvotory.begin() + itemIndex;
	actualInvotory.erase(i);
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
		if (actualInvotory[x] != nullptr)
		{
			//DrawTextEx(ft, actualInvotory[y][x]->GetItemStatistique().c_str(), Vector2{ 950, 5 }, 20, 5, WHITE);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && use == true)
			{
				if (actualInvotory[x]->GetFood() != 0)
				{
					life += actualInvotory[x]->GetFood();
					if (life > maxLife) 
					{
						life = maxLife;
					}
					if (actualInvotory[x]->actualItemStackable > 1)
					{
						actualInvotory[x]->actualItemStackable -= 1;
						use = false;
					}
					else
					{
						actualInvotory[x] = nullptr;
					}
				}
				else if (actualInvotory[x]->GetLearnSpeel() != 0)
				{
					if (actualInvotory[x]->actualItemStackable > 1)
					{
						actualInvotory[x]->actualItemStackable -= 1;
						use = false;
					}
					else
					{
						actualInvotory[x] = nullptr;
					}
				}
				else if (actualInvotory[x]->GetArmor() != 0 )
				{
					actualInvotory[x]->SetEquip();
					if (actualInvotory[x]->GetEquip() == true)
					{
						armorValue += actualInvotory[x]->GetArmor();
					}
					else if (actualInvotory[x]->GetEquip() == false)
					{
						armorValue -= actualInvotory[x]->GetArmor();
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
				money += actualInvotory[x]->itemPrice;
				if (actualInvotory[x]->actualItemStackable > 1) 
				{
					actualInvotory[x]->actualItemStackable -= 1;
					press = false;
				}
				else 
				{
					actualInvotory[x] = nullptr;
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
		if (actualInvotory[x] != nullptr)
		{
			DrawTextEx(ft, actualInvotory[x]->GetItemStatistique().c_str(), Vector2{ 925, 5 }, 25, 5, WHITE);
			if (actualInvotory[x]->GetFood() != 0) 
			{
				DrawTextEx(ft, "Left click for comsum", Vector2{ 925, 475 }, 25, 5, YELLOW);
			}
			else if (actualInvotory[x]->GetLearnSpeel() != 0)
			{
				DrawTextEx(ft, "Left click for", Vector2{ 925, 450 }, 25, 5, YELLOW);
				DrawTextEx(ft, "learn spell", Vector2{ 925, 475 }, 25, 5, YELLOW);
			}
			else if (actualInvotory[x]->GetArmor() != 0 && actualInvotory[y]->GetEquip() == false)
			{
				DrawTextEx(ft, "Left click for equip", Vector2{ 925, 475 }, 25, 5, YELLOW);
			}
			else if (actualInvotory[x]->GetArmor() != 0 && actualInvotory[y]->GetEquip() == true)
			{
				DrawTextEx(ft, "Left click for unequip", Vector2{ 925, 475 }, 25, 5, YELLOW);
			}
			DrawTextEx(ft, "Right click for sell", Vector2{ 925, 500 }, 25, 5, YELLOW);
		}
	}
	int invPos = x / 9;
	Rectangle itemRec{ (int)(100 * (x - (x / 9)*9)), (int)(100 * invPos), 100, 100 };
	if (actualInvotory[x] != nullptr) 
	{
		DrawTexturePro(actualInvotory[x]->itemSprite, Rectangle{0, 0, 400, 400}, itemRec, origin, 0.0f, WHITE);
	}

	DrawTextEx(ft, TextFormat("Armor : %01i ", armorValue), Vector2{ 925, 700 }, 25, 5, LIGHTGRAY);
	DrawTextEx(ft, TextFormat("Actual Hp : %01i/%01i", life, maxLife), Vector2{ 925, 725 }, 25, 5, PINK);
	DrawTextEx(ft, TextFormat("Actual money : %01i ", money, "PO"), Vector2{925, 750}, 25, 5, YELLOW);
}