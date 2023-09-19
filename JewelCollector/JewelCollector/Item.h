#pragma once
#include <string>

class Item {
public:
    Item(std::string type, int value);
    Item(std::string type);

    std::string getType() const;
    int getValue() const;
    void setValue(int newValue);

private:
    std::string type;
    int value;
};

