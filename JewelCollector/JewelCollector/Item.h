#pragma once
#include <string>

class Item {
public:
    Item(std::string type, int value);

    std::string getType() const;
    int getValue() const;
    void setValue(int newValue);

private:
    std::string type;
    int value;
};

