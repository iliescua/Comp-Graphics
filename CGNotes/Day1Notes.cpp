#include<iostream> //<iostream.h> is outdated
#include<fstream> //Use fstream library to read in from file
#include<sstream> //Read words from string 
#include<string>
#include<iomanip> //Format input/output
using namespace std;

int main(int argc, char* argv[]){
	string filename = argv[1];
	cout << argc << endl;
	cout << argv[0] << endl;
	
	//ifstream filein;
	//filein.open("cube.stl");
	
	ifstream filein(filename.c_str());
	string line;

		getline(filein, line);
		getline(filein, line);
		getline(filein, line);
		getline(filein, line);
		cout << line << endl;
	
		istringstream ss(line);
		string word;
		
		ss >> word;
		cout << word << endl;
		
		double number;
		ss >> number;
		cout << fixed << setprecision(4) << setw(20) << number << setw(20) << number << endl;
	// do things here
	
	filein.close();
	return 0;
}