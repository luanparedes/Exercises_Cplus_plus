#include <string>
#include "ToolsData.h"

using namespace std;

ToolsData::ToolsData(int toolRegisterNumber, const string& toolName,
	int toolQuantity, double toolPrice) : registerNumber(toolRegisterNumber), quantity(toolQuantity), price(toolPrice)
{
	setTool(toolName);
}

int ToolsData::getRegisterNumber() const
{
	return registerNumber;
}

void ToolsData::setRegisterNumber(int toolRegisterNumber)
{
	registerNumber = toolRegisterNumber;
}

string ToolsData::getTool() const
{
	return tool;
}

void ToolsData::setTool(const string& toolName)
{
	
}

int ToolsData::getQuantity() const
{
	return quantity;
}

void ToolsData::setQuantity(int toolQuantity)
{
	quantity = toolQuantity;
}

double ToolsData::getPrice() const
{
	return price;
}

void ToolsData::setPrice(double toolprice)
{
	price = toolprice;
}