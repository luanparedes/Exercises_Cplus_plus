#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Jewel.h"
#include "Food.h"
#include "Item.h"
class Treasure {
public:
    int getValue() const;
    void add(Item* item);
    void remove(Item* item);

private:
    std::vector<Item*> items;
};

