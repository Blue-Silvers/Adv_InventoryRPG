#include "Armor.h"

Armor::Armor()
{

}

Armor::Armor(std::string name, int stackable, int maxStackable, int weight, int price, itemEffect effect, int durability, int maxDurability, int protection, armorSlot armorType, Texture2D newItemSprite, uint8_t tag)
{
	itemName = name;
	actualItemStackable = stackable;
	maxItemStackable = maxStackable;
	itemWeight = weight;
	itemPrice = price;
	itemEffectName = effect;
	itemMaxDurability = maxDurability;
	itemDurability = durability;
	armorProtection = protection;
	mTag = tag;
	if ((int)armorType == 0) 
	{
		armoreTypeName = "Helmet";
	}
	else if ((int)armorType == 1)
	{
		armoreTypeName = "Platron";
	}
	else if ((int)armorType == 2)
	{
		armoreTypeName = "Legins";
	}
	else
	{
		armoreTypeName = "Boots";
	}
	itemSprite = newItemSprite;
}

Armor::~Armor()
{
}

int Armor::GetFood()
{
	return 0;
}

int Armor::GetLearnSpeel()
{
	return 0;
}

bool Armor::GetEquip()
{
	return mEquip;
}

bool Armor::SetEquip() 
{
	if (mEquip == true)
	{
		mEquip = false;
	}
	else 
	{
		mEquip = true;
	}
	return true;
}

int Armor::GetArmor()
{
	return armorProtection;
}

string Armor::GetItemStatistique()
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
			"\n\n" << "Durability : " << itemDurability << " / " << itemMaxDurability <<
			"\n\n" << "Protetion : " << armorProtection <<
			"\n\n" << "Armor slot : " << armoreTypeName <<
			"\n\n" << "This item can burning";
	}
	else
	{
		returnValue << "Name : " << itemName <<
			"\n\n" << "Stack of : " << actualItemStackable << " / " << maxItemStackable <<
			"\n\n" << "Weight : " << itemWeight << "Kg" <<
			"\n\n" << "Price : " << itemPrice << "PO" <<
			"\n\n" << "Effect : " << itemEffectText <<
			"\n\n" << "Durability : " << itemDurability << " / " << itemMaxDurability <<
			"\n\n" << "Protetion : " << armorProtection <<
			"\n\n" << "Armor slot : " << armoreTypeName;
	}

	return returnValue.str();
}
