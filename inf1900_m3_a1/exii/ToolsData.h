#pragma once

class ToolsData
{
public:
	ToolsData(int = 0, const std::string & = "", int = 0, double = 0.0);

	void setRegisterNumber(int);
	int getRegisterNumber() const;

	void setTool(const std::string&);
	std::string getTool() const;

	void setQuantity(int);
	int getQuantity() const;

	void setPrice(double);
	double getPrice() const;

private:
	int registerNumber;
	char tool[15];
	int quantity;
	double price;
};