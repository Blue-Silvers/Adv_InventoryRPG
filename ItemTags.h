#pragma once
#include <cstdint>

namespace ItemTag {
	enum Flag {
		Armor = 1 << 0,
		Consumable = 1 << 1,
		Magic = 1 << 2,
		Weapon = 1 << 3,
		Common = 1 << 4,
		Special = 1 << 5,
		Legendary = 1 << 6,
	};

	inline uint8_t operator+(uint8_t& first, Flag& second)
	{
		return first | second;
	}

	inline uint8_t operator-(uint8_t& first, Flag& second)
	{
		return first ^ second;
	}

	inline void operator+=(uint8_t& first, Flag& second)
	{
		first = first | second;
	}

	inline void operator-=(uint8_t& first, Flag& second)
	{
		first = first ^ second;
	}
}

