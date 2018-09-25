#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Person {
	private:
		string fname, lname;
		int age;

	public:

	 Person(string first, string last, int ag) {
	 	fname = first;
	 	lname = last;
	 	age = ag;
	 }

	 string ToString() {
	 	// We need to combine strings and int 
	 	// return fname + " " + lname + " " + age;
	 	stringstream stm;
	 	stm<<fname << " " << lname << " " << age;
	 	return stm.str();
	 }
};

int main() {
	Person person("Aditya", "Earanky", 27);
	cout<<person.ToString()<<endl;
	return 0;
}