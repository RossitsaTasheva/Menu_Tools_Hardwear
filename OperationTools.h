/*
 * OperationTools.h
 *
 *  Created on: 17.05.2017 г.
 *      Author: Rossi
 */

#ifndef OPERATIONTOOLS_H_
#define OPERATIONTOOLS_H_
#include <iostream>
#include "Tool.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
using namespace std;

enum Choices { PRINT = 1, UPDATE, NEW, DELETE, END };

class OperationTools {
public:
	OperationTools();
	OperationTools(vector <Tool*> &);

	int enterChoice();
	void print();
	void createTextFile (fstream&);
	void updateRecord(fstream&);
	void newRecord(fstream&);
	void deleteRecord(fstream&);
	void outputLine(ostream&, const Tool &);
	int getRecord(const char * const);
	void initialize();

	virtual ~OperationTools();
	const vector<Tool*>& getHardwere() const;
	void setHardwere(const vector<Tool*>& hardwere);

private:
	vector <Tool*> hardwere;
};

#endif /* OPERATIONTOOLS_H_ */
