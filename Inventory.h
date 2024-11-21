#pragma once
#include <iostream>
#include "vector"
#include "Item.h"
#include "FoodProcessor.h"

using namespace std;

class Inventory
{
private :
	int money = 0;
    int life = 50;
    int maxLife = 100;
    int armorValue = 0;
    bool press = true;
    bool use = true;
	Texture2D foreGround, backGround;

public :
	
    vector<Item*>::iterator it;

    vector<Item*> actualInvotory;
    vector<Item*> weaponInvotory;
    vector<Item*> magicInvotory;
    vector<Item*> consumableInvotory;
    vector<Item*> armorInvotory;

    Item* foodRecepies[2]{ nullptr, nullptr };

    Inventory();
    void AddToInventory(Item* newItem);
    void RemoveFromInventory(int itemIndex);
	void Draw(int x, int y, Font ft);
    void DrawItem(int x, Font ft);
	void Start();
    void Update(int x, Font ft);
    void ActualiseUnvotory();
};

