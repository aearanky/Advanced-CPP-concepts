#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1("clear");
	string s2("clean");
	
	/*Compares letters at every index - so cLER is still greater than clear 		because R or r > a*/
	if(s1 > s2) {
		cout<<s1<< " is greater than "<< s2 << endl;
	} else 
			cout<<s2<< " is greater than "<< s1 << endl;
			
	//or use s1.compare(s2) - results in 1, 0 or -1
	
	/*Find substrings*/
	string str1("Find a needle in a haystack");
	string str2("needle");
	
	cout <<"Found needle at: "<< str1.find(str2)<<endl;
	
	/*Get substring*/
	cout <<"Needle isolated: "<<str1.substr(str1.find(str2), str2.length()) 			<<endl;
	
	/*Replace "needle" with "pin"*/
	str1.replace(str1.find(str2), str2.length(), "pin");
	cout <<"String after needle is replaced by pin: "<< str1 <<endl;
	return 0;
}
