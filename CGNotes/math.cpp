#include <iostream>
#include"math.h"
using namespace std;

int add(int a, int b){
    return a+b;
}

int main(){
    int x = 5;
    int y = 3;
    int sum;
    sum = add(x,y);
    cout << "Sum is " << sum << endl;

    return 0;
}