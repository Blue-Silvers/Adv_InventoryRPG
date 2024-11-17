#pragma once
#include "IBakable.h"
#include "Consumable.h"
#include "Inventory.h"

class FoodProcessor : public IBakable
{
public:
	FoodProcessor(Inventory* inventory);

	void Cook(Consumable& consumableItem) override;
	void GetNewCookedItem(Consumable& consumableItem);

private:
	Inventory* mInventory = new Inventory();
};

