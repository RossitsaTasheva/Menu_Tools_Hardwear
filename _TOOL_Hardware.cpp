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
	fstream inOutTool( "hardware.dat", ios::in | ios::out );        if ( !inOutTool )        {           cerr << "File could not be opened." << endl;           exit ( 1 );        }        int choice;
        while ( ( choice = enterChoice() ) != END )        {           switch ( choice )           {              case PRINT:                 createTextFile( inOutTool );                 break;              case UPDATE:                 updateRecord(  inOutTool );                 break;              case NEW:                 newRecord(  inOutTool );                 break;              case DELETE:                 deleteRecord(  inOutTool );                 break;              default: //                 cerr << "Incorrect choice" << endl;                 break;           }         inOutTool.clear();        }        return 0;     }//----------------------------------------------------------------------------------------------------------------------------------------     int enterChoice()     {      cout << "\n--------Enter your choice----------------------------" << endl          << "---------1 - store a formatted text file of record-------" << endl           << "-------called \"print.txt\" for printing--------------" << endl           << "--------2 - update an record--------------------------" << endl           << "--------3 - add a new record--------------------------" << endl           << "--------4 - delete record-----------------------------" << endl           << "--------5 - end program\n? --------------------------";        int menuChoice;        cin >> menuChoice;        return menuChoice;     }
// called \"print.txt\" for printing---------------------------------------------     void createTextFile( fstream &readFromFile )     {    	 ofstream outPrintFile( "print.txt", ios::out );    	 if ( !outPrintFile )        {           cerr << "File could not be created." << endl;           exit( 1 );        }
    	  cout<<"t1~~~~~~~~~~~~~~~~~~~~"<<endl;        outPrintFile << left << setw( 10 ) << "Record" << setw( 16 )           << "Name" << setw( 11 ) << "Quantity" << right           << setw( 10 ) << "cost" << endl;
        cout<<"t2~~~~~~~~~~~~~~~~~~~~"<<endl;
        readFromFile.seekg( 0 );        Tool tool;        readFromFile.read( reinterpret_cast< char * >( &tool),  sizeof( Tool ) );
             cout<<"t3~~~~~~~~~~~~~~~~~~~~"<<endl;        while ( !readFromFile.eof() ){if ( tool.getRecord() != 0 )              outputLine( outPrintFile, tool );
           readFromFile.read( reinterpret_cast< char * >( &tool ),sizeof( Tool ) );        }
        cout<<"t4~~~~~~~~~~~~~~~~~~~~"<<endl;     }
//update an record-------------------------------------------------------------     void updateRecord( fstream &updateFile ){    	 int record = getRecord( "Enter account to update" );    	 updateFile.seekg( ( record - 1 ) * sizeof( Tool ) );
    	 Tool tool;        updateFile.read( reinterpret_cast< char * >( &tool ),           sizeof( Tool ) );        if ( tool.getRecord() != 0 ){           outputLine( cout, tool );           updateFile.seekp( ( record - 1 ) * sizeof( Tool) );           updateFile.write( reinterpret_cast< const char * >( &tool),              sizeof( Tool ) );        }        else cerr << "Record #" << record << " has no information." << endl;     }
//add a new record----------------------------------------------------------     void newRecord( fstream & insertInFile ) {

        int record = getRecord( "Enter new tool record" );        insertInFile.seekg( ( record - 1 ) * sizeof( Tool ) );
        cout<<"1~~~~~~~~~~~~~~~~~~~~"<<endl;        Tool tool;        insertInFile.read( reinterpret_cast< char * >( &tool ),sizeof( Tool ) );        if ( tool.getRecord() == 0 )   {          char name[20];           int quantity;           double cost;              cout<<"2~~~~~~~~~~~~~~~~~~~~"<<endl;           cout << "Enter record, name, quantity, cost\n? ";           cin >>  record;           cin >>  name		   ;           cin >> quantity;           cin >> cost;               cout<<"3~~~~~~~~~~~~~~~~~~~~"<<endl;
               Tool tool2;           tool2.setRecord( record);           tool2.setName( name );           tool2.setQuantity( quantity );           tool2.setCost( cost );

           cout<<"4~~~~~~~~~~~~~~~~~~~~"<<endl;
           insertInFile.seekp( ( record - 1 ) * sizeof( Tool ) );
           cout<<"5~~~~~~~~~~~~~~~~~~~~"<<endl;           insertInFile.write( reinterpret_cast< const char * >( &tool2 ),
                   sizeof( Tool ) );
           cout<<"6~~~~~~~~~~~~~~~~~~~~"<<endl;        }        else           cerr << "Record #" << record              << " already contains information." << endl;     }
//delete record--------------------------------------------------------------     void deleteRecord( fstream &deleteFromFile )     {        int record = getRecord( "Enter record to delete" );        deleteFromFile.seekg( ( record - 1 ) * sizeof( Tool ) );        Tool tool;        deleteFromFile.read( reinterpret_cast< char * >( &tool ),           sizeof( Tool) );        if ( tool.getRecord() != 0 )  {           Tool blankTool;           deleteFromFile.seekp( ( record - 1 ) * sizeof( Tool ) );           deleteFromFile.write(              reinterpret_cast< const char * >( &blankTool ),              sizeof( Tool ) );           cout << "Record #" << record << " deleted.\n";
        }    else           cerr << "Record #" << record << " is empty.\n";     }//outputLine-----------------------------------------------------------------     void outputLine( ostream &output, const Tool &rec ){        output << left << setw( 10 ) << rec.getRecord()           << setw( 16 ) << rec.getName()           << setw( 11 ) << rec.getQuantity()           << setw( 10 ) << setprecision( 2 ) << right << fixed           << showpoint << rec.getCost() << endl;     }//getRecord----------------------------------------------------------------------     int getRecord( const char * const prompt )     {        int record;        do   {           cout << prompt << " (1 - 100): ";           cin >> record;        } while ( record < 1 || record > 100 );        return record;     }