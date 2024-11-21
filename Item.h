#pragma once
#include "raylib.h"
#include "iFlammable.h"
#include "ItemTags.h"
#include <iostream>
#include <sstream>
using namespace std;

	enum itemEffect
	{
		FIRE,
		ICE,
		WATER,
		EARTH,
		HEAL,
		LIGHT,
		VOID,
		NONE,
	};

class Item : public iFlammable
{
public:
	bool showInfo = false;
	string itemName = "Bob";
	int maxItemStackable = 1;
	int actualItemStackable = 1;
	int itemWeight = 1;
	int itemPrice = 1;
	Texture2D itemSprite;
	itemEffect itemEffectName = NONE;
	uint8_t mTag =0;

	Item();
	Item(string name, int stackable, int maxStackable, int weight, int price, itemEffect effect, Texture2D newItemSprite, uint8_t tag);

	virtual string GetItemStatistique() = 0;
	virtual int GetFood() = 0;
	virtual int GetLearnSpeel() = 0;
	virtual bool GetEquip() = 0;
	virtual bool SetEquip() = 0;
	virtual int GetArmor() = 0;

	bool Burning() override;
	bool CompareTag(uint8_t tag);
};

