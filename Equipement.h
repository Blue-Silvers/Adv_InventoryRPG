#pragma once
#include "Item.h"

class Equipement : public Item
{
private:

public:
	int itemDurability = 1;
	int itemMaxDurability = 1;

	Equipement();
	Equipement(string name, int stackable, int maxStackable, int weight, int price, itemEffect effect, int durability, int maxDurability, Texture2D newItemSprite, uint8_t tag);

	string GetItemStatistique() override;
	int GetFood() override;
	virtual int GetLearnSpeel() override;
	virtual bool GetEquip() override;
	virtual bool SetEquip() override;
	virtual int GetArmor() override;
};

