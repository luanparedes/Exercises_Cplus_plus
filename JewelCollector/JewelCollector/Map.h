#pragma once

#include <iostream>
#include <vector>
#include "Treasure.h"

class Map {
public:
    Map(int width, int height);

    void add(int x, int y, Item* item);
    void remove(int x, int y);
    void show() const;

private:
    int width;
    int height;
    std::vector<std::vector<char>> map;
    Treasure treasure;
    std::vector<Item*> treasItems; 
};