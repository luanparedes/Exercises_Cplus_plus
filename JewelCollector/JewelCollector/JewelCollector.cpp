/*
Author: Anderson Aparecido Barreto Furlan
Author: Luan Lucas de Simas Paredes
*/

#include <iostream>
#include "Map.h"
using namespace std;

enum MenuOptions {
    InvalidOption,
    PrintOption,
    ModifyOption,
    RobotOption,
    ExitOption,
    JewelOption,
    FoodOption
};
void printModifyMenu(Map* map);
MenuOptions resolveOption(string input);

int main()
{
    Map map(10, 10);

    map.add(0, 0, new Jewel(45));
    map.add(4, 4, new Food(25));
    map.add(9, 9, new Jewel(30));

    bool isQuit = false;
    string optionTyped;

    while (!isQuit) {
        cout << "Enter 'exit' to quit, 'print' for show the map, 'modify' to modify it or 'robot' for robot actions: ";
        cin >> optionTyped;

        switch (resolveOption(optionTyped))
        {
            case PrintOption:
                map.show();
                break;
            case ModifyOption:
                printModifyMenu(&map);
                break;
            case RobotOption:
                robotActions();
            case InvalidOption:
                cout << "Invalid value. Enter a correct type 'jewel' or 'food'." << endl;
                break;
            case ExitOption:
            default:
                isQuit = true;
                break;
        }
    }
    return 0;
}

void printModifyMenu(Map* map) {
    int x, y;
    string optionTyped;
    int itemValue;

    cout << "Enter position x: ";
    cin >> x;
    cout << "Enter position y: ";
    cin >> y;
    cout << "Enter the type of item (jewel or food): ";
    cin >> optionTyped;
    cout << "Enter the value of item: ";
    cin >> itemValue;

    switch (resolveOption(optionTyped)) 
    {
        case JewelOption:
            map->remove(x, y);
            map->add(x, y, new Jewel(itemValue));
            break;
        case FoodOption:
            map->remove(x, y);
            map->add(x, y, new Food(itemValue));
            break;
        default:
            cout << "Invalid value. Enter a correct type 'jewel' or 'food'." << endl;
            break;
    }
}

void robotActions() {
    char selectedOption;

    cout << "W - UP\nS - DOWN\nA - LEFT\nD - RIGHT\nG - Collect/use item";
    cin >> selectedOption;

    switch (selectedOption) {
    case 'W':
    case 'S':
    case 'A':
    case 'D':
    case 'G':
    default:
        return;
    }
}

MenuOptions resolveOption(std::string input) {

    if (input == "exit") return ExitOption;
    if (input == "print") return PrintOption;
    if (input == "modify") return ModifyOption;
    if (input == "robot") return RobotOption;
    if (input == "jewel") return JewelOption;
    if (input == "food") return FoodOption;

    return InvalidOption;
}