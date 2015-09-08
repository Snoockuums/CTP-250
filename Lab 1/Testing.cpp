    #include <iostream>
	 #include <string>
	 
	 using namespace std;
     
   int main()
	{
    string inputValue;
 
    do {
        cout << "Type words. Type quit to end: ";
        cin >>inputValue;
		  
		  //added this if statement to catch an immediate 'quit'
		  if(inputValue == "quit")
		  	break;
 
        cout << "Your string was: " << inputValue << endl;
    }
    while (inputValue != "quit");
 
    return 0;
	}