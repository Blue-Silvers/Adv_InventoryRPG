#pragma once
#include "Item.h"

class Magic : public Item
{
private:
	int spellDuration = 1;

public:
	int spellLevel = 1;

	Magic();
	Magic(string name, int stackable, int maxStackable, int weight, int price, itemEffect effect, int level, int duration, Texture2D newItemSprite, uint8_t tag);

	string GetItemStatistique() override;
	int GetFood() override;
	virtual int GetLearnSpeel() override;
	virtual bool GetEquip() override;
	virtual bool SetEquip() override;
	virtual int GetArmor() override;

};

