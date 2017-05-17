/*
 * Tool.h
 *
 *  Created on: May 16, 2017
 *      Author: rossitsa
 */

#ifndef TOOL_H_
#define TOOL_H_
#include <string>
#include <iostream>
using namespace std;

class Tool {
public:
	Tool();
	Tool(int,string,int,double);

	virtual ~Tool();

	double getCost() const;
	void setCost(double cost);


	int getQuantity() const;
	void setQuantity(int quantity);

	int getRecord() const;
	void setRecord(int record);

	void print();

	const string& getName() const;
	void setName(const string& name);

private:
	int record;
	string name;
	int quantity;
	double cost;
};

#endif /* TOOL_H_ */
