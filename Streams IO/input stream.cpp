#include <iostream>
#include <string>

using namespace std;

int main() {

	string name1, name2;
	cout<<"Enter your name: ";
	
	// Enter a name with a space to see the difference with using cin and then using getline
	cin >> name1; 
	cout << name1 << endl;

	// At this point comment out the previous 'cin' code to test the difference 
	
	// Method 1
	cout<<"Enter your name: ";
	getline(cin,name2); // Waits for a new line as input till it breaks
	cout << name2 << endl;

	// Method 2 --> Picked from the days of C
	cout<<"Enter your name: ";
	char c;
	c = cin.get();
	do {
		cout.put(c);
		c = cin.get();
	} while(!cin.eof());  // We need ctrl +  Z to exit the program

	return 0;
}