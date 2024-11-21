#pragma once
#include "Item.h"

class Consumable : public Item
{
private:


public:
	int healing = 1;

	Consumable();
	Consumable(string name, int stackable, int maxStackable, int weight, int price, itemEffect effect, int heal, Texture2D newItemSprite, uint8_t tag);

	string GetItemStatistique() override;
	int GetFood() override;
	virtual int GetLearnSpeel() override;
	virtual bool GetEquip() override;
	virtual bool SetEquip() override;
	virtual int GetArmor() override;
};

