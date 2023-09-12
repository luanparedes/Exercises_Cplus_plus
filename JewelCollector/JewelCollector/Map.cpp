#include "Map.h"
#include "Item.h"

Map::Map(int width, int height) : width(width), height(height), treasure(Treasure()) {
    for (int y = 0; y < height; y++) {
        std::vector<char> row;
        for (int x = 0; x < width; x++) {
            row.push_back(' ');
        }
        map.push_back(row);
    }
}

void Map::add(int x, int y, Item* item) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
          map[y][x] = item->getType()[0];
        treasure.add(item);
        treasItems.push_back(item);
    }
    else {
        std::cout << "The position is out of range, try again" << std::endl << std::endl;
    }
}

void Map::remove(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        char itemType = map[y][x];
        if (itemType != ' ') {
            for (auto it = treasItems.begin(); it != treasItems.end(); ++it) {
                if ((*it)->getType()[0] == itemType) {
                    treasure.remove(*it);
                    treasItems.erase(it);
                    break;
                }
            }
            map[y][x] = ' ';
         
        }
    }
}

void Map::show() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Number of jewels in the treasure: " << treasItems.size() << std::endl;
    std::cout << "Total treasure value: " << treasure.getValue() << std::endl;
}