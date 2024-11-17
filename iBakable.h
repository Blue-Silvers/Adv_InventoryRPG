#pragma once
#include "Consumable.h"

class IBakable
{
	virtual void Cook(Consumable& consumableItem) = 0;
};

