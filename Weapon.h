#pragma once
#include "Equipement.h"

class Weapon : public Equipement
{
private:

public:
	int itemDamage = 1;
	//int itemRange = 1;
	float itemAttackSpeed = 1.0;

	Weapon();
	Weapon(string name, int stackable, int maxStackable, int weight, int price, itemEffect effect, int durability, int maxDurability, int damage, float attackSpeed, Texture2D itemSprite, uint8_t tag);
	void Start();

	string GetItemStatistique() override;
	int GetFood() override;
	virtual int GetLearnSpeel() override;
	virtual bool GetEquip() override;
	virtual bool SetEquip() override;
	virtual int GetArmor() override;
};

