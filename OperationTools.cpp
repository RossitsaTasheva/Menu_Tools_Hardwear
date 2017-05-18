/*
 * OperationTools.cpp
 *
 *  Created on: 17.05.2017 г.
 *      Author: Rossi
 */

#include "OperationTools.h"
OperationTools::OperationTools() {

}
OperationTools::OperationTools(vector<Tool*>& hardwere) {

}

OperationTools::~OperationTools() {
}

const vector<Tool*>& OperationTools::getHardwere() const {
	return hardwere;
}

void OperationTools::initialize() {
	ofstream fout("hardware.dat", ios::binary);

		if (!fout) {
			cerr << "File could not be opened." << endl;
			exit(1);
		}

		Tool t;
		for (int i = 0; i < 100; i++)
			fout.write(reinterpret_cast<const char *>(&t), sizeof(Tool));
}

void OperationTools::setHardwere(const vector<Tool*>& hardwere) {
	this->hardwere = hardwere;
}
void OperationTools::print() {
}
//enterChoice---------------------------------------------------------------------------------
int OperationTools::enterChoice() {

	cout << "\n~~~~~~~~~~~Enter your choice~~~~~~~" << endl
			<< "------1 - store a formatted text file of record-------" << endl
			<< "-------called \"print.txt\" for printing--------------" << endl
			<< "--------2 - update an record--------------------------" << endl
			<< "--------3 - add a new record--------------------------" << endl
			<< "--------4 - delete record-----------------------------" << endl
			<< "--------5 - end program\n? --------------------------";

	int menuChoice;
	cin >> menuChoice;
	return menuChoice;

}
// called \"print.txt\" for printing---------------------------------------------
void OperationTools::createTextFile(fstream& readFromFile) {
	ofstream outPrintFile("print.txt");
	if (!outPrintFile) {
		cerr << "File could not be created." << endl;
		exit(1);
	}
	cout << "t1~~~~~~~~~~~~~~~~~~~~" << endl;
	outPrintFile << left << setw(10) << "Record" << setw(16) << "Name"
			<< setw(11) << "Quantity" << right << setw(10) << "cost" << endl;
	cout << "t2~~~~~~~~~~~~~~~~~~~~" << endl;
	readFromFile.seekg(0);
	Tool t;
	readFromFile.read(reinterpret_cast<char *>(&t), sizeof(Tool));
	cout << "t3~~~~~~~~~~~~~~~~~~~~" << endl;
	while (!readFromFile.eof()) {
		if (t.getRecord() != 0)
			outputLine(outPrintFile, t);
		readFromFile.read(reinterpret_cast<char *>(&t), sizeof(Tool));
	}
	cout << "t4~~~~~~~~~~~~~~~~~~~~" << endl;
}
//update an record-------------------------------------------------------------

void OperationTools::updateRecord(fstream& updateFile) {
	int record = getRecord("Enter account to update");
	updateFile.seekg((record - 1) * sizeof(Tool));
	Tool tool;
	updateFile.read(reinterpret_cast<char *>(&tool), sizeof(Tool));
	if (tool.getRecord() != 0) {
		outputLine(cout, tool);
		updateFile.seekp((record - 1) * sizeof(Tool));
		updateFile.write(reinterpret_cast<const char *>(&tool), sizeof(Tool));
	} else
		cerr << "Record #" << record << " has no information." << endl;
}
//newRecord-------------------------------------------------------------

void OperationTools::newRecord(fstream& insertInFile) {
	int record = getRecord("Enter new tool record");
	insertInFile.seekg((record - 1) * sizeof(Tool));
	cout << "1~~~~~~~~~~~~~~~~~~~~" << endl;
	Tool tool;
	insertInFile.read(reinterpret_cast<char *>(&tool), sizeof(Tool));
	if (tool.getRecord() == 0) {
		char name[20];
		int quantity;
		double cost;
		cout << "2~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Enter record, name, quantity, cost\n? ";
		cin >> record;
		cin >> name;
		cin >> quantity;
		cin >> cost;
		cout << "3~~~~~~~~~~~~~~~~~~~~" << endl;
		Tool tool2;
		tool2.setRecord(record);
		tool2.setName(name);
		tool2.setQuantity(quantity);
		tool2.setCost(cost);

		cout << "4~~~~~~~~~~~~~~~~~~~~" << endl;

		insertInFile.seekp((record - 1) * sizeof(Tool));
		cout << "5~~~~~~~~~~~~~~~~~~~~" << endl;
		insertInFile.write(reinterpret_cast<const char *>(&tool2),
				sizeof(Tool));
		cout << "6~~~~~~~~~~~~~~~~~~~~" << endl;
	} else
		cerr << "Record #" << record << " already contains information."
				<< endl;
}

//deleteRecord-------------------------------------------------------------

void OperationTools::deleteRecord(fstream& deleteFromFile) {
	int record = getRecord("Enter record to delete");
	deleteFromFile.seekg((record - 1) * sizeof(Tool));
	Tool tool;
	deleteFromFile.read(reinterpret_cast<char *>(&tool), sizeof(Tool));

	if (tool.getRecord() != 0) {
		Tool blankTool;
		deleteFromFile.seekp((record - 1) * sizeof(Tool));
		deleteFromFile.write(reinterpret_cast<const char *>(&blankTool),
				sizeof(Tool));
		cout << "Record #" << record << " deleted.\n";
	} else
		cerr << "Record #" << record << " is empty.\n";
}

void OperationTools::outputLine(ostream& output, const Tool& rec) {
	output << left << setw(10) << rec.getRecord() << setw(16) << rec.getName()
			<< setw(11) << rec.getQuantity() << setw(10) << setprecision(2)
			<< right << fixed << showpoint << rec.getCost() << endl;
}

int OperationTools::getRecord(const char* const prompt) {
	int record;

	do {
		cout << prompt << " (1 - 100): ";
		cin >> record;
	} while (record < 1 || record > 100);
	return record;
}

