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
    string word;
    string data[] = {};
    int numFacets = 0;
    int x,y,z = 0;
    int min_x,min_y,min_z = 0;
    int max_x,max_y,max_z = 0;

    while(getline(filein, line)){
        istringstream ss(line);
        ss >> word;
        if(word == "vertex"){
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
            //data[numFacets] = line; //SEG FAULTS HERE
            numFacets++;
        }
    }
    numFacets /= 3;
    int count = 0;
    // for(int i = 0; i < numFacets; i++){
    //     printf("Facet: %d       x   y   z", i);
    //     while(count < 3){
    //         cout << data[count] << endl;
    //         count++;
    //     }
    // }
	
	filein.close();
	return 0;
}