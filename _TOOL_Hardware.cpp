//============================================================================
// Name        : _TOOL_Hardware.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Tool.h"
#include <iostream>
#include "Tool.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "OperationTools.h"
using namespace std;

int main() {

	OperationTools op;

	//op.initialize();

	fstream inOutTool( "hardware.dat", ios::in | ios::out );        if ( !inOutTool ){           cerr << "File could not be opened." << endl;           exit ( 1 );        }

        int choice;        while ( ( choice = op. enterChoice() ) != END )        {        	switch ( choice )           {        		case PRINT:  op.createTextFile( inOutTool ); break;        		case UPDATE:  op.updateRecord(  inOutTool ); break;        		case NEW:    op.newRecord(  inOutTool );   break;
        		case DELETE:    op.deleteRecord(  inOutTool );    break;        		default:   cerr << "Incorrect choice" << endl;    break;        	}         inOutTool.clear();        }       return 0;    }