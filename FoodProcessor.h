#pragma once
#include "IBakable.h"
#include "Consumable.h"
#include "GameInit.h"

class FoodProcessor : public IBakable
{
public:
	FoodProcessor();

	Item* Cook(Item* consumableItem, Item* secondConsumableItem) override;
	Consumable* vegetableStew;
	Consumable* mushroomPremiumSteak;
};

