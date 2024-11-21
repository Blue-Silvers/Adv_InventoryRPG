#pragma once
#include <cstdint>

namespace FoodTag {
	enum FoodFlag {
		Vegetable = 1 << 0,
		Herb = 1 << 1,
		Mushroom = 1 << 2,
		Meat = 1 << 3,
		Other = 1 << 4,
	};

	inline uint8_t operator+(uint8_t& first, FoodFlag& second)
	{
		return first | second;
	}

	inline uint8_t operator-(uint8_t& first, FoodFlag& second)
	{
		return first ^ second;
	}

	inline void operator+=(uint8_t& first, FoodFlag& second)
	{
		first = first | second;
	}

	inline void operator-=(uint8_t& first, FoodFlag& second)
	{
		first = first ^ second;
	}
}

