#pragma once

#include "Item.h"
#include "Map.h"
#include "Food.h"
#include <vector>

class Robot : public Item
{
public:
	Robot(int initialEnergy);
	void walk();
	void eat(Food *food);
	void collect(Jewel *jewel);

private:
	int energy;
	std::vector<Item> bag;
	Map memoryMap;
};

