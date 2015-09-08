    #include <iostream>
	 
	 using namespace std;
     
   int main()
{
    int num;
 
    do {
        cout << "Insert a integer: ";
        cin >> num;
 
        cout << "Your number was: " << num << endl;
    }
    while (num != -1);
 
    return 0;
}