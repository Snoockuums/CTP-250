// Kylie Nicholson
// 

//includes

#include <iostream>

using namespace std; 

int add(int first, int second){
	int result = first + second;
	if(result == 4)
		throw logic_error("four!"); 
	return result; 
}

int main(){
	
	try{
		add(2,2); 
	}
	catch(logic_error e)
	{
		cout<<e.what()<<endl; 
	}
	
}