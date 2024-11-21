#pragma once
#include "Consumable.h"

class IBakable
{
	virtual Item* Cook(Item* consumableItem, Item* secondConsumableItem) = 0;
};

