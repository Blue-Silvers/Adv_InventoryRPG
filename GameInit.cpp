#include "GameInit.h"


GameInit::GameInit() 
{

}

void GameInit::Init()
{
	broadSword = new Physical("Broadsword", 1, 5, 2, 200, NONE, 342, 500, 6, 0.5, 5, LoadTexture("resources/Icone/Broadsword.png"), ItemTag::Weapon);

	cactusSword = new Physical("Cactus Sword", 1, 1, 3, 800, EARTH, 1000, 1000, 15, 0.6, 8, LoadTexture("resources/Icone/Cactussword.png"), ItemTag::Weapon);

	meteorStrike = new Magic("Meteor Strike", 1, 20, 1, 500, FIRE, 2, 40, LoadTexture("resources/Icone/MeteorStrike.png"), ItemTag::Magic);

	summonSatan = new Magic("Summon Satan", 1, 1, 1, 7500, VOID, 3, 666, LoadTexture("resources/Icone/SummonSatan.png"), ItemTag::Magic);

	poseidonStaff = new Staff("Poseidon's Staff", 1, 1, 10, 2000, WATER, 6000, 6000, 50, 5.2, 4000, LoadTexture("resources/Icone/PoseidonStaff.png"), ItemTag::Weapon);

	bread = new Consumable("Bread", 16, 64, 1, 5, NONE, 20, LoadTexture("resources/Icone/Bread.png"), ItemTag::Consumable, FoodTag::Other);

	honey = new Consumable("Honey", 10, 100, 1, 20, EARTH, 5, LoadTexture("resources/Icone/Honey.png"), ItemTag::Consumable, FoodTag::Other);

	chainedChesplate = new Armor("Iron-chained Chestplate", 1, 5, 25, 250, EARTH, 120, 300, 4, BODY, LoadTexture("resources/Icone/IronChainedChestplate.png"), ItemTag::Armor);

	spartaHelmet = new Armor("Sparta Helmet", 1, 5, 5, 400, FIRE, 232, 400, 6, HEAD, LoadTexture("resources/Icone/SpartaHelmet.png"), ItemTag::Armor);


	chicken = new Consumable("Chicken", 1, 1, 5, 25, FIRE, 5, LoadTexture("resources/Icone/Chicken.png"), ItemTag::Consumable, FoodTag::Meat);
	chanterelles = new Consumable("Chanterelles", 1, 1, 1, 70, WATER, 15, LoadTexture("resources/Icone/Chanterelles.png"), ItemTag::Consumable, FoodTag::Mushroom);
	herbsBundle = new Consumable("Herbs bundle", 1, 1, 2, 10, HEAL, 2, LoadTexture("resources/Icone/HerbsBundle.png"), ItemTag::Consumable, FoodTag::Herb);
	bokChoy = new Consumable("Bok choy", 1, 1, 1, 60, EARTH, 13, LoadTexture("resources/Icone/BokChoy.png"), ItemTag::Consumable, FoodTag::Vegetable);

}