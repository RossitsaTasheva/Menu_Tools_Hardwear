//============================================================================
// Name        : _TOOL_Hardware.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Tool.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

int enterChoice();
void createTextFile(fstream&);
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);
void outputLine(ostream&, const Tool &);
int getRecord(const char * const);

enum Choices { PRINT = 1, UPDATE, NEW, DELETE, END};

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
	fstream inOutTool( "hardware.dat", ios::in | ios::out );

// called \"print.txt\" for printing---------------------------------------------
    	  cout<<"t1~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"t2~~~~~~~~~~~~~~~~~~~~"<<endl;
        readFromFile.seekg( 0 );
             cout<<"t3~~~~~~~~~~~~~~~~~~~~"<<endl;
           readFromFile.read( reinterpret_cast< char * >( &tool ),sizeof( Tool ) );
        cout<<"t4~~~~~~~~~~~~~~~~~~~~"<<endl;
//update an record-------------------------------------------------------------
    	 Tool tool;
//add a new record----------------------------------------------------------


        cout<<"1~~~~~~~~~~~~~~~~~~~~"<<endl;
               Tool tool2;

           cout<<"4~~~~~~~~~~~~~~~~~~~~"<<endl;

           cout<<"5~~~~~~~~~~~~~~~~~~~~"<<endl;
                   sizeof( Tool ) );
           cout<<"6~~~~~~~~~~~~~~~~~~~~"<<endl;

        }    else