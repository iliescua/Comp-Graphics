#include<iostream> //<iostream.h> is outdated
#include<fstream>  //Use fstream library to read in from file
#include<sstream>  //Read words from string 
#include<iomanip>  //Format input/output
#include<string>
#include<stdio.h>
using namespace std;

int main(int argc, char* argv[]){
	string filename = argv[1];
	ifstream filein(filename.c_str());
	string line;
    string word;
    string data;
    int numFacets = 0;
    float x=0,y=0,z=0;
    float min_x=0,min_y=0,min_z=0;
    float max_x=0,max_y=0,max_z=0;
    float count=0,temp=0;

    while (count < 6){
        getline(filein, line);
        istringstream ss(line);
        ss >> word;
        if(word == "vertex"){
            ss >> max_x;
            min_x = max_x;
            ss >> max_y;
            min_y = max_y;
            ss >> max_z;
            min_z = max_z;
            numFacets++;
            printf("\nFacet: %d\n", numFacets);
            data = line;
            while(temp < 3){
                cout << data << endl;
                getline(filein, data);
                temp++;
            }
        }
        temp = 0;
        count++;
    }
    count = 0;

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
            numFacets++;
            data = line;
            printf("\nFacet: %d\n", numFacets);
            while(count < 3){
                cout << data << endl;
                getline(filein, data);
                count++;
            }
            count = 0;
        }
    }
    printf("\n\nTotal Number of Facets is %d\n\n", numFacets);
    printf("\nLargest x: %f", max_x);
    printf("\nLargest y: %f", max_y);
    printf("\nLargest z: %f\n", max_z);
    printf("\nSmallest x: %f", min_x);
    printf("\nSmallest y: %f", min_y);
    printf("\nSmallest z: %f\n", min_z);
	
	filein.close();
	return 0;
}