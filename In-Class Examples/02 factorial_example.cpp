/** Recursive factorial example
* @file recursive_example.cpp
* @author Kylie Nicholson
*/

#include <iostream>
using namespace std;

int fact(int);

int main(){

	int input = 0;
	
	while (input != -1)
	{
		cout<<"Enter an integer or -1 to quit"<<endl;
		cin>>input;
		
		if (input != -1){
			cout<<"The factorial of "<<input<<" is "<< fact(input) <<endl<< endl;
		}
}
}

int fact(int n){
	int factorial;
	
	if(n<0) {
	cout<<"Error! Negative number."<<endl;
	factorial =0;
	}
	else if (n==0)
		factorial =1; 
	else
		factorial = n*fact(n-1); 
	
	return(factorial);
}