#include<iostream>
#include<list>
#include<string>

using namespace std;

int main() {
	list<string> names;
	names.push_back("Aditya");
	names.push_back("Korey");

	list<string>::iterator it = names.begin();
	while(it != names.end()){
		cout<< *it << endl;
		++it;
	}

	return 0;
}