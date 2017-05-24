/*
 * Operations.h
 *
 *  Created on: May 16, 2017
 *      Author: LyBo-Pc
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_
#include "Tool.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>


using namespace std;
class Operations {
private:
	fstream file;
public:
	int enterChoice();
	void createTextFile();
	void updateRecord();
	void newRecord();
	void deleteRecord();
	void outputLine(ostream&,const Tool&);
	int getTool(const char* const);

	Operations(const char*);
	virtual ~Operations();
};

#endif /* OPERATIONS_H_ */
