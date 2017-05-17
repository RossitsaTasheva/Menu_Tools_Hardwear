/*
 * Tool.cpp
 *
 *  Created on: May 16, 2017
 *      Author: rossitsa
 */

#include "Tool.h"

Tool::Tool() {
	 setRecord(0);
	 setName("NULL");
     setQuantity(0);
     setCost(0.0);
}
Tool::Tool(int record, string name, int quantity, double cost) {
	setRecord(record);
	setName(name);
	setQuantity(quantity);
	setCost(cost);
}

Tool::~Tool() {}

double Tool::getCost() const {
	return cost;
}

void Tool::setCost(double cost) {
	this->cost = cost;
}

int Tool::getQuantity() const {
	return quantity;
}

void Tool::setQuantity(int quantity) {
	this->quantity = quantity;
}

int Tool::getRecord() const {
	return record;
}

void Tool::setRecord(int record) {
	this->record = record;
}
const string& Tool::getName() const {
	return name;
}

void Tool::setName(const string& name) {
	this->name = name;
}

void Tool::print() {
	cout<<  "|"<<getRecord()<<getName()<<"|"<<getQuantity()<<"|"<<getCost()<<"|"<<endl;
}


