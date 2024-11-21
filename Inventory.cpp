#include "Inventory.h"

Inventory::Inventory()
{
}

void Inventory::AddToInventory(Item* newItem)
{

	bool hole = false;
	for (int x = 0; x < actualInvotory.size(); x++)
	{
		if (actualInvotory[x] == nullptr && hole == false)
		{
			it = actualInvotory.begin() + x;
			actualInvotory.insert(it, newItem);
			hole = true;
		}
	}
	if(hole == false)
	{
		actualInvotory.push_back(newItem);
	}

	
}

void Inventory::RemoveFromInventory(int itemIndex)
{
	actualInvotory[itemIndex] = nullptr;
}

void Inventory::Start()
{
	foreGround = LoadTexture("resources/Icone/BG_Item.png");
	backGround = LoadTexture("resources/Icone/BG_Description.png");
}

void Inventory::Update(int x, Font ft)
{
	int invPos = x / 9;
	Rectangle rec{ (int)(100 * (x - (x / 9) * 9)), (int)(100 * invPos), 100, 100 };
	if (CheckCollisionPointRec(GetMousePosition(), rec))
	{
		if (actualInvotory[x] != nullptr)
		{
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
					RemoveFromInventory(x);
				}
			}
			if (IsMouseButtonReleased(MOUSE_BUTTON_RIGHT) && press == false)
			{
					press = true;
			}
		}
	}
}

//Actualise inventory at end of the loop
void Inventory::ActualiseUnvotory()
{
	for (int i = 0; i < actualInvotory.size(); i++)
	{
		if (actualInvotory[i] == nullptr)
		{
			actualInvotory.erase(actualInvotory.begin() + i);
		}
	}

	//stock item
	for (int x = 0; x < actualInvotory.size(); x++)
	{
		if (actualInvotory[x]->CompareTag(ItemTag::Weapon))
		{
			weaponInvotory.push_back(actualInvotory[x]);
		}
		if (actualInvotory[x]->CompareTag(ItemTag::Magic))
		{
			magicInvotory.push_back(actualInvotory[x]);
		}
		if (actualInvotory[x]->CompareTag(ItemTag::Consumable))
		{
			consumableInvotory.push_back(actualInvotory[x]);
		}
		if (actualInvotory[x]->CompareTag(ItemTag::Armor))
		{
			armorInvotory.push_back(actualInvotory[x]);
		}
	}

	// reset inv
	actualInvotory.clear();

	//Weapon at first
	for (int x = 0; x < weaponInvotory.size(); x++)
	{
		actualInvotory.push_back(weaponInvotory[x]);
	}
	//Magic at second
	for (int x = 0; x < magicInvotory.size(); x++)
	{
		actualInvotory.push_back(magicInvotory[x]);
	}
	//Consumable at Third
	for (int x = 0; x < consumableInvotory.size(); x++)
	{
		actualInvotory.push_back(consumableInvotory[x]);
	}
	//Armor at end
	for (int x = 0; x < armorInvotory.size(); x++)
	{
		actualInvotory.push_back(armorInvotory[x]);
	}

	//reset all vector for next use
	weaponInvotory.clear();
	magicInvotory.clear();
	consumableInvotory.clear();
	armorInvotory.clear();
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

	


	DrawTextEx(ft, TextFormat("Armor : %01i ", armorValue), Vector2{ 925, 700 }, 25, 5, LIGHTGRAY);
	DrawTextEx(ft, TextFormat("Actual Hp : %01i/%01i", life, maxLife), Vector2{ 925, 725 }, 25, 5, PINK);
	DrawTextEx(ft, TextFormat("Actual money : %01i ", money, "PO"), Vector2{925, 750}, 25, 5, YELLOW);
}

void Inventory::DrawItem(int x, Font ft)
{
	Vector2 origin{ 0, 0 };
	int invPos = x / 9;
	Rectangle itemRec{ (int)(100 * (x - (x / 9) * 9)), (int)(100 * invPos), 100, 100 };

	if (CheckCollisionPointRec(GetMousePosition(), itemRec))
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
			else if (actualInvotory[x]->GetArmor() != 0 && actualInvotory[x]->GetEquip() == false)
			{
				DrawTextEx(ft, "Left click for equip", Vector2{ 925, 475 }, 25, 5, YELLOW);
			}
			else if (actualInvotory[x]->GetArmor() != 0 && actualInvotory[x]->GetEquip() == true)
			{
				DrawTextEx(ft, "Left click for unequip", Vector2{ 925, 475 }, 25, 5, YELLOW);
			}
			DrawTextEx(ft, "Right click for sell", Vector2{ 925, 500 }, 25, 5, YELLOW);
		}
	}

	if (actualInvotory[x] != nullptr)
	{
		DrawTexturePro(actualInvotory[x]->itemSprite, Rectangle{ 0, 0, 400, 400 }, itemRec, origin, 0.0f, WHITE);
	}
	/*if (physicalInvotory[x] != nullptr)
	{
		Rectangle itemRec{ (int)(100 * (x - (x / 9) * 9)), (int)(100 * invPos), 100, 100 };
		DrawTexturePro(physicalInvotory[x]->itemSprite, Rectangle{ 0, 0, 400, 400 }, itemRec, origin, 0.0f, WHITE);
	}
	if (magicInvotory[x] != nullptr)
	{
		Rectangle itemRec{ (int)(100 * (x - (x / 9) * 9)), (int)(100 * (invPos + 1)), 100, 100 };
		DrawTexturePro(magicInvotory[x]->itemSprite, Rectangle{ 0, 0, 400, 400 }, itemRec, origin, 0.0f, WHITE);
	}
	if (staffInvotory[x] != nullptr)
	{
		Rectangle itemRec{ (int)(100 * (x - (x / 9) * 9)), (int)(100 * (invPos + 2)), 100, 100 };
		DrawTexturePro(staffInvotory[x]->itemSprite, Rectangle{ 0, 0, 400, 400 }, itemRec, origin, 0.0f, WHITE);
	}
	if (armorInvotory[x] != nullptr)
	{
		Rectangle itemRec{ (int)(100 * (x - (x / 9) * 9)), (int)(100 * (invPos + 3)), 100, 100 };
		DrawTexturePro(armorInvotory[x]->itemSprite, Rectangle{ 0, 0, 400, 400 }, itemRec, origin, 0.0f, WHITE);
	}
	if (consumableInvotory[x] != nullptr)
	{
		Rectangle itemRec{ (int)(100 * (x - (x / 9) * 9)), (int)(100 * (invPos + 4)), 100, 100 };
		DrawTexturePro(consumableInvotory[x]->itemSprite, Rectangle{ 0, 0, 400, 400 }, itemRec, origin, 0.0f, WHITE);
	}*/
}