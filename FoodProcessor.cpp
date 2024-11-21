#include "FoodProcessor.h"

FoodProcessor::FoodProcessor()
{
	vegetableStew = new Consumable("Vegetable stew", 1, 1, 3, 200, LIGHT, 50, LoadTexture("resources/Icone/VegetableStew.png"), ItemTag::Consumable, FoodTag::Other);
	mushroomPremiumSteak = new Consumable("Mushroom premium steak", 1, 1, 6, 350, VOID, 75, LoadTexture("resources/Icone/MushroomPremiumSteak.png"), ItemTag::Consumable, FoodTag::Other);
}

Item* FoodProcessor::Cook(Item* consumableItem, Item* secondConsumableItem)
{
	if (consumableItem->foodType != secondConsumableItem->foodType)
	{
		if (((consumableItem->foodType == FoodTag::Vegetable) && (secondConsumableItem->foodType == FoodTag::Herb)) || ((consumableItem->foodType == FoodTag::Herb) && (secondConsumableItem->foodType == FoodTag::Vegetable)))
		{
			return vegetableStew;
		}
		else if (((consumableItem->foodType == FoodTag::Meat) && (secondConsumableItem->foodType == FoodTag::Mushroom)) || ((consumableItem->foodType == FoodTag::Mushroom) && (secondConsumableItem->foodType == FoodTag::Meat)))
		{
			return mushroomPremiumSteak;
		}
		else 
		{
			return consumableItem;
		}
	}
	else
	{
		return consumableItem;
	}
}
