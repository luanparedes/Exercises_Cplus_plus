#include "Item.h"

Item::Item(std::string type, int value) : type(type), value(value) {}

std::string Item::getType() const {
    return type;
}

int Item::getValue() const {
    return value;
}

void Item::setValue(int newValue) {
    value = newValue;
}