#pragma once
#include "Weapon.h"

class Physical : public Weapon
{
protected:
	int itemRange = 1;

public:


	Physical();
	Physical(string name, int stackable, int maxStackable, int weight, int price, itemEffect effect, int durability, int maxDurability, int damage, float attackSpeed, int range, Texture2D newItemSprite);

	string GetItemStatistique() override;
	int GetFood() override;
	virtual int GetLearnSpeel() override;
	virtual bool GetEquip() override;
	virtual bool SetEquip() override;
	virtual int GetArmor() override;

};

