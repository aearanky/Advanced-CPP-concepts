#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main() {
	
	/*Allows duplicate keys*/
	multimap<string, string> numbers;
	numbers.insert(pair<string, string> ("Aditya", "100"));
	numbers.insert(pair<string, string> ("Prajakta", "95"));
	numbers.insert(pair<string, string> ("Aditya", "98"));
	numbers.insert(pair<string, string> ("Ankita", "95"));
	numbers.insert(pair<string, string> ("Aditya", "96"));
	
	string searchName = "Aditya";
	multimap<string, string>::iterator iter = numbers.find(searchName);
	multimap<string, string>::iterator last = numbers.upper_bound(searchName);
	
	/*Displays only those occurences where the given key repeats*/
	for(; iter != last; iter++) {
		cout<< iter->first << ": "<< iter->second <<endl;
	}
	return 0;
}
