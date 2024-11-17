#pragma once
#include <iostream>
#include "vector"
#include "Item.h"


using namespace std;

class Inventory
{
private :
	int money = 0;
    int life = 50;
    int maxLife = 100;
    int armorValue = 0;
    bool press = true;
    bool use = true;
	Texture2D foreGround, backGround;

public :
	
	Item* actualInvotory[8][9]{
        { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
    };

    Inventory();
	void Draw(int x, int y, Font ft);
	void Start();
    void Update(int x, int y, Font ft);
};

