#include "Magic.h"

Magic::Magic() 
{

}

Magic::Magic (std::string name, int stackable, int maxStackable, int weight, int price, itemEffect effect, int level, int duration, Texture2D newItemSprite)
{
	itemName = name;
	actualItemStackable = stackable;
	maxItemStackable = maxStackable;
	itemWeight = weight;
	itemPrice = price;
	itemEffectName = effect;
	spellLevel = level;
	spellDuration = duration;
	itemSprite = newItemSprite;
}

int Magic::GetFood()
{
	return 0;
}

int Magic::GetLearnSpeel()
{
	return spellLevel;
}

bool Magic::GetEquip()
{
	return 0;
}

bool Magic::SetEquip()
{
	return 0;
}

int Magic::GetArmor()
{
	return 0;
}

string Magic::GetItemStatistique()
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
	returnValue << "Name : " << itemName <<
		"\n\n" << "Stack of : " << actualItemStackable << " / " << maxItemStackable <<
		"\n\n" << "Weight : " << itemWeight << "Kg" <<
		"\n\n" << "Price : " << itemPrice << "PO" <<
		"\n\n" << "Effect : " << itemEffectText <<
		"\n\n" << "Spell level : " << spellLevel <<
		"\n\n" << "Spell duration : " << spellDuration;

	if (Burning() == true) 
	{
		returnValue << "Name : " << itemName <<
			"\n\n" << "Stack of : " << actualItemStackable << " / " << maxItemStackable <<
			"\n\n" << "Weight : " << itemWeight << "Kg" <<
			"\n\n" << "Price : " << itemPrice << "PO" <<
			"\n\n" << "Effect : " << itemEffectText << 
			"\n\n" << "This item can burning";
	}
	else
	{
		returnValue << "Name : " << itemName <<
			"\n\n" << "Stack of : " << actualItemStackable << " / " << maxItemStackable <<
			"\n\n" << "Weight : " << itemWeight << "Kg" <<
			"\n\n" << "Price : " << itemPrice << "PO" <<
			"\n\n" << "Effect : " << itemEffectText;
	}

	return returnValue.str();
}

