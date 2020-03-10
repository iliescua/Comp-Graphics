#include<iostream> //<iostream.h> is outdated
#include<fstream>  //Use fstream library to read in from file
#include<sstream>  //Read words from string 
#include<iomanip>  //Format input/output
#include<string>
using namespace std;

int main(int argc, char* argv[]){
	string filename = argv[1];
	ifstream filein(filename.c_str());
	string line;
    while(getline(filein, line)){
        if(line == "vertex"){
            cout << line << endl;
        }
    }
    istringstream ss(line);
    string word;
    
    ss >> word;
    double number;
    ss >> number;
    cout << fixed << setprecision(4) << setw(20) << number << setw(20) << number << endl;
	
	filein.close();
	return 0;
}