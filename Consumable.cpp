#include "Consumable.h"

Consumable::Consumable()
{

}

Consumable::Consumable(string name, int stackable, int maxStackable, int weight, int price, itemEffect effect, int heal, Texture2D newItemSprite, uint8_t tag)
{
	itemName = name;
	actualItemStackable = stackable;
	maxItemStackable = maxStackable;
	itemWeight = weight;
	itemPrice = price;
	itemEffectName = effect;
	healing = heal;
	itemSprite = newItemSprite;
	mTag = tag;
}

int Consumable::GetFood()
{
	return healing;
}

int Consumable::GetLearnSpeel()
{
	return 0;
}

bool Consumable::GetEquip()
{
	return 0;
}

bool Consumable::SetEquip()
{
	return 0;
}

int Consumable::GetArmor()
{
	return 0;
}

string Consumable::GetItemStatistique()
{
	string itemEffectText;
	if (itemEffectName == 0)
	{
		itemEffectText = "Fire";
	}
	else if (itemEffectName == 1)
	{
		itemEffectText = "Ice";
	}
	else if (itemEffectName == 2)
	{
		itemEffectText = "Water";
	}
	else if (itemEffectName == 3)
	{
		itemEffectText = "Earth";
	}
	else if (itemEffectName == 4)
	{
		itemEffectText = "Heal";
	}
	else if (itemEffectName == 5)
	{
		itemEffectText = "Light";
	}
	else if (itemEffectName == 6)
	{
		itemEffectText = "Void";
	}
	else if (itemEffectName == 7)
	{
		itemEffectText = "None";
	}
	std::ostringstream returnValue;

	if (Burning() == true)
	{
		returnValue << "Name : " << itemName <<
			"\n\n" << "Stack of : " << actualItemStackable << " / " << maxItemStackable <<
			"\n\n" << "Weight : " << itemWeight << "Kg" <<
			"\n\n" << "Price : " << itemPrice << "PO" <<
			"\n\n" << "Effect : " << itemEffectText <<
			"\n\n" << "Healing : " << healing << "Hp" <<
			"\n\n" << "This item can burning";
	}
	else
	{
		returnValue << "Name : " << itemName <<
			"\n\n" << "Stack of : " << actualItemStackable << " / " << maxItemStackable <<
			"\n\n" << "Weight : " << itemWeight << "Kg" <<
			"\n\n" << "Price : " << itemPrice << "PO" <<
			"\n\n" << "Effect : " << itemEffectText <<
			"\n\n" << "Healing : " << healing << "Hp";
	}

	return returnValue.str();
}

