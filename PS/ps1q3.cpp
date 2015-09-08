#include <iostream>
#include <string>
#include <locale>
#include <iomanip>
	 
using namespace std;


float num = 7.43822;
    cout << fixed;
    cout << setprecision (2) << setfill('#'); 
    cout << setw(7) << num << endl;