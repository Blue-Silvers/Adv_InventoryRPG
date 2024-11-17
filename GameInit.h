#pragma once
#include "Inventory.h"
#include "Weapon.h"
#include "Staff.h"
#include "Physical.h"
#include "Magic.h"
#include "Item.h"
#include "Equipement.h"
#include "Consumable.h"
#include "Armor.h"

class GameInit
{
private:

public:
	Physical* broadSword;
	Physical* cactusSword;
	Magic* meteorStrike;
	Magic* summonSatan;
	Staff* poseidonStaff;
	Consumable* bread;
	Consumable* honey;
	Armor* chainedChesplate;
	Armor* spartaHelmet;

	GameInit();
	void Init(Inventory inv);

};

