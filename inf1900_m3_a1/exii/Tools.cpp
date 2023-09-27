#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> 
#include "ToolsData.h"

using namespace std;

int enterChoice();
void createTextFile(fstream&);
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);
void outputLine(ostream&, const ToolsData&);
int getRegister(const char* const);

enum Options { SHOW = 1, NEW, EDIT, DELETE, END };

int main()
{
    fstream inOutTools("hardware.dat", ios::in | ios::out | ios::binary);

    if (!inOutTools)
    {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    int choice;

    while ((choice = enterChoice()) != END)
    {
        switch (choice)
        {
        case SHOW:
            createTextFile(inOutTools);
            break;
        case NEW:
            newRecord(inOutTools);
            break;
        case EDIT:
            updateRecord(inOutTools);
            break;
        case DELETE:
            deleteRecord(inOutTools);
            break;
        default:
            cerr << "Incorrect choice" << endl;
            break;
        }

        inOutTools.clear();
    }
}

int enterChoice()
{
    cout << "\nEnter your choice" << endl
        << "1 - Show all tools" << endl
        << "2 - Add a new tool" << endl
        << "3 - Edit a tool" << endl
        << "4 - Delete a tool" << endl
        << "5 - Exit\n? ";

    int menuChoice;
    cin >> menuChoice;
    return menuChoice;
}

void createTextFile(fstream& readFromFile)
{
    ofstream outPrintFile("all_tools.txt", ios::out);

    if (!outPrintFile)
    {
        cerr << "File could not be created." << endl;
        exit(EXIT_FAILURE);
    }

    outPrintFile << left << setw(10) << "Register" << setw(16)
        << "Tool" << setw(11) << "Quantity" << right
        << setw(10) << "Price" << endl;

    readFromFile.seekg(0);

    ToolsData tools;

    readFromFile.read(reinterpret_cast<char*>(&tools),
        sizeof(ToolsData));

    while (!readFromFile.eof())
    {
        if (tools.getRegisterNumber() != 0)
            outputLine(outPrintFile, tools);

        readFromFile.read(reinterpret_cast<char*>(&tools),
            sizeof(ToolsData));
    }
} 

void updateRecord(fstream& updateFile)
{
    int accountNumber = getRegister("Enter account to update");

    updateFile.seekg((accountNumber - 1) * sizeof(ToolsData));

    ToolsData tools;

    updateFile.read(reinterpret_cast<char*>(&tools),
        sizeof(ToolsData));

    if (tools.getRegisterNumber() != 0)
    {
        outputLine(cout, tools);

        cout << "\nEnter charge (+) or payment (-): ";
        double transaction;
        cin >> transaction;

        double oldBalance = tools.getPrice();
        tools.setPrice(oldBalance + transaction);
        outputLine(cout, tools); 

        updateFile.seekp((accountNumber - 1) * sizeof(ToolsData));

        updateFile.write(reinterpret_cast<const char*>(&tools),
            sizeof(ToolsData));
    }
    else
        cerr << "Account #" << accountNumber
        << " has no information." << endl;
} 

void newRecord(fstream& insertInFile)
{
    int registerNumber = getRegister("Enter new register number");

    insertInFile.seekg((registerNumber - 1) * sizeof(ToolsData));

    ToolsData tools;

    insertInFile.read(reinterpret_cast<char*>(&tools),
        sizeof(ToolsData));

    if (tools.getRegisterNumber() == 0)
    {
        string tool;
        int quantity;
        double price;

        cout << "Enter tool, quantity, price\n? ";
        cin >> tool;
        cin >> quantity;
        cin >> price;

        tools.setTool(tool);
        tools.setQuantity(quantity);
        tools.setPrice(price);
        tools.setRegisterNumber(registerNumber);

        insertInFile.seekp((registerNumber - 1) * sizeof(ToolsData));
                      
        insertInFile.write(reinterpret_cast<const char*>(&tools),
            sizeof(ToolsData));
    } 
    else 
        cerr << "Register #" << registerNumber
        << " already contains information." << endl;
}

void deleteRecord(fstream& deleteFromFile)
{
    int registerNumber = getRegister("Enter register to delete");

    deleteFromFile.seekg((registerNumber - 1) * sizeof(ToolsData));

    ToolsData tools;

    deleteFromFile.read(reinterpret_cast<char*>(&tools),
        sizeof(ToolsData));

    if (tools.getRegisterNumber() != 0)
    {
        ToolsData blankTool;

        deleteFromFile.seekp((registerNumber - 1) *
            sizeof(ToolsData));

        deleteFromFile.write(
            reinterpret_cast<const char*>(&blankTool),
            sizeof(ToolsData));

        cout << "Register #" << registerNumber << " deleted.\n";
    }
    else
        cerr << "Register #" << registerNumber << " is empty.\n";
}

void outputLine(ostream& output, const ToolsData& record)
{
    output << left << setw(10) << record.getRegisterNumber()
        << setw(16) << record.getTool()
        << setw(11) << record.getQuantity()
        << setw(10) << setprecision(2) << right << fixed
        << showpoint << record.getPrice() << endl;
}


int getRegister(const char* const prompt)
{
    int registerNumber;

    do
    {
        cout << prompt << " (1 - 100): ";
        cin >> registerNumber;
    } while (registerNumber < 1 || registerNumber > 100);

    return registerNumber;
}