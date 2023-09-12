#include <iostream>
#include "Map.h"
using namespace std;

enum MenuOptions {
    Invalid,
    Print,
    Modify,
    Exit
};

MenuOptions resolveOption(string input);

int main()
{
    Map map(10, 10);

    map.add(2, 3, new Jewel(50));
    map.add(4, 5, new Jewel(30));
    map.add(7, 8, new Food(20));

    bool isQuit = false;
    string userInput;

    while (!isQuit) {
        cout << "Enter 'exit' to quit, 'print' for show the map or 'modify' to modify it: ";
        cin >> userInput;

        switch (resolveOption(userInput))
        {
            case Exit:
            default:
                isQuit = true;
                break;
            case Invalid:
                cout << "Invalid value. Enter a correct type 'jewel' or 'food'." << endl;
                break;
            case Print:
                map.show();
                break;
            case Modify:
                int x, y;
                string itemType;
                int itemValue;

                cout << "Enter position (x, y) para modify the map: ";
                cin >> x >> y;
                cout << "Enter the type of item (jewel or food): ";
                cin >> itemType;
                cout << "Enter the value of item: ";
                cin >> itemValue;

                if (itemType == "jewel") {
                    map.add(x, y, new Jewel(itemValue));
                }
                else if (itemType == "food") {
                    map.add(x, y, new Food(itemValue));
                }
                else {
                    cout << "Invalid value. Enter a correct type 'jewel' or 'food'." << endl;
                }
                break;
        }
        
    }
    return 0;
}

MenuOptions resolveOption(std::string input) {
    if (input == "exit") return Exit;
    if (input == "print") return Print;
    if (input == "modify") return Modify;
    return Invalid;
}