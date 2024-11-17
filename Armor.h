#pragma once
#include "Equipement.h"
#include <sstream>

enum armorSlot
{
	HEAD,
	BODY,
	LEGS,
	BOOTS,
};

class Armor : public Equipement
{
private:
	enum armorSlot mArmorSlot;
	

public:
	int armorProtection = 1;
	string armoreTypeName = "None";
	bool mEquip = false;
	Armor();
	Armor(string name, int stackable, int maxStackable, int weight, int price, itemEffect effect, int durability, int maxDurability, int protection, armorSlot armorType, Texture2D newItemSprite);
	~Armor();

	string GetItemStatistique() override;
	int GetFood() override;
	virtual int GetLearnSpeel() override;
	virtual bool GetEquip() override;
	virtual bool SetEquip() override;
	virtual int GetArmor() override;
};

