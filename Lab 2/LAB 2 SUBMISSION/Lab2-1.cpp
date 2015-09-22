/**
 * @file Lab1-1.cpp
 * @author Kylie Nicholson
 *
 * Determines whether a word begins with a vowel, a consonant or other. Then outputs
 * count of each category (vowel, consonant, or other)
 */

#include <iostream>

using namespace std;

void printStars(int num);

int main()
{
    int theInput;
    cout<<"How many stars should I print?"<<endl;
    cin>>theInput;
    printStars(theInput);
}

void printStars(int num) {
    
    if(num > 0){
        cout<<"*";
        printStars(num-1);
    }

}