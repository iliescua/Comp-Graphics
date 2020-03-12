#include<iostream> //<iostream.h> is outdated
#include<fstream>  //Use fstream library to read in from file
#include<sstream>  //Read words from string 
#include<iomanip>  //Format input/output
#include<string>
using namespace std;

int main(int argc, char* argv[]){
	string filename = argv[1];
	ifstream filein(filename.c_str());
	string line; //Line from file
    string word; //A word in the line
    string data; //Used as a temp variable for line
    int numFacets = 0; //Keeps track of facets
    float x=0,y=0,z=0; //Initializes the x,y,z coordinates
    float min_x=0,min_y=0,min_z=0; //Initialized to store min coordinates
    float max_x=0,max_y=0,max_z=0; //Initialized to store max coordinates
    float count=0,temp=0; //Temp variabls used in calculations
    int firstSet = 6; //First set of data size

    //Iterates through first set of data
    while (count < firstSet){
        getline(filein, line);
        istringstream ss(line);
        ss >> word;
        if(word == "vertex"){
            //Loads in first set of data into the min and max values to be used later
            ss >> max_x;
            min_x = max_x;
            ss >> max_y;
            min_y = max_y;
            ss >> max_z;
            min_z = max_z;
            numFacets++;
            cout << "\nFacets: " << numFacets << endl;
            data = line;
            //Prints out the first set of vertex values
            while(temp < 3){
                cout << data << endl;
                getline(filein, data);
                temp++;
            }
        }
        temp = 0;
        count++;
    }
    count = 0; //Resets count

    //Iterates through the rest of the file
    while(getline(filein, line)){
        istringstream ss(line);
        ss >> word;
        if(word == "vertex"){
            //Loads vertex values and compares them for min and max
            ss >> x;
            ss >> y;
            ss >> z;
            if(x > max_x){
                max_x = x;
            }
            if(x < min_x){
                min_x = x;
            }
            if(y > max_y){
                max_y = y;
            }
            if(y < min_y){
                min_y = y;
            }
            if(z > max_z){
                max_z = z;
            }
            if(z < min_z){
                min_z = z;
            }
            numFacets++;
            data = line;
            cout << "\nFacets: " << numFacets << endl;
            //Used to print out all three lines of vertex data in 1 facet
            while(count < 3){
                cout << data << endl;
                getline(filein, data);
                count++;
            }
            count = 0;
        }
    }
    //Used to print out results at the end
    cout << "\n\nTotal Number of Facets is " << numFacets << "\n\n" << endl;
    cout << "Largest x: " << max_x << endl;
    cout << "Largest y: " << max_y << endl;
    cout << "Largest z: " << max_z << "\n" << endl;
    cout << "Smallest x: " << min_x << endl;
    cout << "Smallest y: " << min_y << endl;
    cout << "Smallest z: " << min_z << endl;
	
	filein.close();
	return 0;
}