#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <vector>


using std::vector;
using namespace std;
int mainMenu();

int main (){
	
	int option=0;
	bool isStringValid=0;
	string inputString= " ";
	string outputString= " ";
	vector<string> fileNames;
	
	
	cout << "DNA Sequence Database Software\n" << endl; 
	cout << "Specify the name of DNA sequence file names you would like to load. "; 
	cout << "For multiple files, add a <<,>> between each file name. \n " << endl;
	cout << ">";
	cin >> inputString;
	ifstream fileIn;
	ofstream fileOut;
	
	stringstream sin(inputString);

	
	while (sin.good()) {
		cout << "Everything is good: " << sin.good() << endl;
		getline (sin, outputString, ',');
		ifstream fileIn (outputString);
		if (fileIn)
			fileNames.push_back(outputString);
		else 
			cout << "Can't open input file " << outputString << endl;
		
	}

	
	
	int a=fileNames.size();
	cout<<"The number of elements in the string is: " <<a<<endl;
	
	option = mainMenu();
	cout << char(option) <<endl;
return 0;
}

int mainMenu() {
	char selection = 0;
	cout << "Select one of the following options" << endl;
	cout << "(S) Summary statistics of the DNA database" << endl;
	cout << "(1) Analyse DNA_sequence_1" << endl;
	cout << "(2) Analyse DNA_sequence_2" << endl;
	cout << "(3) Analyse DNA_sequence_3" << endl;
	cout << "(4) Analyse DNA_sequence_4" << endl;
	cout << "(Q) Quit" << endl;
	
if ((selection < 1) || (selection > 6) || ((selection!=53) && (selection!=81)))
	{	char originalSelection;
		cout << ">";
		cin >> originalSelection;
		selection=toupper(originalSelection);
	}
	cout << endl;
	
	return selection;
}