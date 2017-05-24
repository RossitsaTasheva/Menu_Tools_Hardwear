//============================================================================
// Name        : FilesEx1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<cstdlib>
#include "Tool.h"
#include "Operations.h"
#include "globals.h"
using namespace std;



int main() {



	ofstream outTools("hardware.dat",ios::binary);
	if(!outTools){
		cerr<<"File can`t open"<<endl;
		exit(1);
	}
Tool blankTools;
for ( int i = 0; i < 100; i++ )
      outTools.write( reinterpret_cast< const char * >( &blankTools ),
         sizeof( Tool ) );



	Operations hardware("hardware.dat");
int choice;

while((choice=hardware.enterChoice())!= END)
{
	switch(choice){
	case PRINT: hardware.createTextFile(); break;
	case UPDATE: hardware.updateRecord(); break;
	case NEW: hardware.newRecord(); break;
	case DELETE: hardware.deleteRecord(); break;
	default: cerr<<"Wrong choice"; break;

	}
}
	return 0;
}
