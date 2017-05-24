/*
 * Tool.h
 *
 *  Created on: May 16, 2017
 *      Author: LyBo-Pc
 */

#ifndef TOOL_H_
#define TOOL_H_
#include<iostream>
#include<string>
using namespace std;

class Tool {
private:
	int number;
	string name;
	int quantity;
	double price;
public:
	Tool(int = 0,string = " ",int = 0,double = 0);
	virtual ~Tool();
	const string& getName() const;
	void setName(const string& name);
	int getNumber() const;
	void setNumber(int number);
	double getPrice() const;
	void setPrice(double price);
	int getQuantity() const;
	void setQuantity(int quantity);
};

#endif /* TOOL_H_ */
