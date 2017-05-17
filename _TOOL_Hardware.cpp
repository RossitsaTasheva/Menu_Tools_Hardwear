//============================================================================
// Name        : _TOOL_Hardware.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "OperationTools.h"
#include "Tool.h"

#include <iostream>
#include "Tool.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {

	/*ofstream fout("hardware.dat", ios::binary);

	if (!fout) {
		cerr << "File could not be opened." << endl;
		exit(1);
	}

	Tool t;
	for (int i = 0; i < 100; i++)
		fout.write(reinterpret_cast<const char *>(&t), sizeof(Tool));

	return 0;
}*/
	vector <Tool*> hardwere;
	Tool t(1, "www", 2, 2.3	);
	hardwere.push_back(&t);
	t.print();

	fstream inOutTool( "hardware.dat", ios::in | ios::out );        if ( !inOutTool ){           cerr << "File could not be opened." << endl;           exit ( 1 );        }
        int choice;        while ( ( choice = enterChoice() ) != END )        {           switch ( choice )           {              case PRINT:                 createTextFile( inOutTool );                 break;              case UPDATE:                 updateRecord(  inOutTool );                 break;              case NEW:                 newRecord(  inOutTool );                 break;              case DELETE:                 deleteRecord(  inOutTool );                 break;              default: //                 cerr << "Incorrect choice" << endl;                 break;           }         inOutTool.clear();        }        return 0;     }