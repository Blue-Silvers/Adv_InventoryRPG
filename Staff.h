#pragma once
#include "Weapon.h"

class Staff : public Weapon
{
protected:
	int itemMaxMana = 1;

public:


	Staff();
	Staff(string name, int stackable, int maxStackable, int weight, int price, itemEffect effect, int durability, int maxDurability, int damage, float attackSpeed, int maxMana,Texture2D newItemSprite);

	string GetItemStatistique() override;
	int GetFood() override;
	virtual int GetLearnSpeel() override;
	virtual bool GetEquip() override;
	virtual bool SetEquip() override;
	virtual int GetArmor() override;
};

