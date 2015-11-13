//
//  main.cpp
//  FiguringShitOut
//
//  Created by Kylie Nicholson on 10/20/15.
//  Copyright (c) 2015 Kylie Nicholson. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "rectangle.h"

using namespace std;

// define a class
// move the class to a seperate file and link it to this one
// create a template class
// link to template class (different #include)
// create a virtual class
// link virtual to class
// actually write up the bag ADT myself
// write up recursive backtracking algorithm
// write up towers of hanoi algorithm

/*class rectangle {
private:
    int width;
    int height;
    
public:
    rectangle();
    rectangle(int, int);
    int area();
};

rectangle::rectangle(){
    width =0;
    height = 0;
}

rectangle::rectangle(int w, int h){
    width = w;
    height = h;
}

int rectangle::area(){
    int area = width * height;
    return area;
}*/

int main() {
    // insert code here...
    string theline;
    cout << "I am going to write to a file"<<endl;
    ofstream myfile;
    myfile.open("samplefile.txt");
    myfile<<"Hello World!"<<endl;
    myfile.close();
    ifstream inputfile;
    inputfile.open("samplefile.txt");
    getline(inputfile, theline);
    cout<<"The file says: "<<theline<<endl;
    inputfile.close();
    return 0;
}
