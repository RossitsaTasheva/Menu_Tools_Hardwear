/*
 * Tool.cpp
 *
 *  Created on: May 16, 2017
 *      Author: LyBo-Pc
 */

#include "Tool.h"

const string& Tool::getName() const {
	return name;
}

void Tool::setName(const string& name) {
	this->name = name;
}

int Tool::getNumber() const {
	return number;
}

void Tool::setNumber(int number) {
	this->number = number;
}

double Tool::getPrice() const {
	return price;
}

void Tool::setPrice(double price) {
	this->price = price;
}

int Tool::getQuantity() const {
	return quantity;
}

Tool::Tool(int number, string name, int quantity, double price) {
	setNumber(number);
	setName(name);
	setQuantity(quantity);
	setPrice(price);
}

void Tool::setQuantity(int quantity) {
	this->quantity = quantity;
}

Tool::~Tool() {
	// TODO Auto-generated destructor stub
}

