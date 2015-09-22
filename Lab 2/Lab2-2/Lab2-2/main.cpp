/**
* @file: Lab2-2.cpp
* @author: Kylie Nicholson
* This file takes an input string and displays its words backwards. The string must end with a
* space (because of the method I use to parse the words), and an EOF (per Lab instructions).
* 
*/

#include <string>
#include <iostream>

using namespace std;

int writeBackwards(string, int);

int main(){
    string theString;
    
    cout<<"Enter a String: "<<endl;
    while(cin.peek() != EOF){
        getline(cin,theString);
    }
    writeBackwards(theString, 0);
    
    //writeBackwards("Hello my name is Kylie ", 0); // FILE WORKS WITH THIS!!!!!!
    return 0;
}

int writeBackwards(string s, int start)
{
    size_t spaceLoc = 0;
    
    if(start >= s.length()-1)
        return 0; // or some other base case
    
    spaceLoc = s.find(' ', start);
    //    spaceLoc2 = s.find(' ', (int)spaceLoc+1);
    string wordBuilder;
    
    for(int i=start; i<=spaceLoc; i++)
    {
        wordBuilder += s[i];
        //cout<<wordBuilder;
    }
    
    int spaceLocInt= (int)spaceLoc;
    
    writeBackwards(s, spaceLocInt+1);
    cout<<wordBuilder;
    
    return 0;
}