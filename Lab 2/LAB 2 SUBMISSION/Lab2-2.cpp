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
    return 0;
}

int writeBackwards(string s, int start)
{
    size_t spaceLoc = 0;
    
    if(start >= s.length()-1)
        return 0; // base case
    
    spaceLoc = s.find(' ', start);
    string wordBuilder;
    
    for(int i=start; i<=spaceLoc; i++)
    {
        wordBuilder += s[i];
    }
    
    int spaceLocInt= (int)spaceLoc;
    
    writeBackwards(s, spaceLocInt+1);
    cout<<wordBuilder;
    
    return 0;
}