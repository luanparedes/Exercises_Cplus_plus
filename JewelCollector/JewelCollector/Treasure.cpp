#include "Treasure.h"

int Treasure::getValue() const {
    int total = 0;
    for (const auto& item : items) {
        total += item->getValor();
    }
    return total;
}

void Treasure::add(Item* item) {
    items.push_back(item);
}

void Treasure::remove(Item* item) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == item) {
            items.erase(it);
            delete item;
            break;
        }
    }
}