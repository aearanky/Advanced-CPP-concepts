#include <iostream>
#include <map>

using namespace std;

int main() {
	/*Maps are based on pair class*/
	
	/*Part 1*/
	map<string, string> numbers;
	numbers["Aditya"] = "369";
	numbers["Ronnie"] = "38";
	
	cout<<"Aditya: "<< numbers["Aditya"] <<endl;
	cout<< "Size: " << numbers.size() <<endl;	
	numbers.erase("Ronnie");
	cout<< "Size after erasing Ronnie: " << numbers.size() <<endl;
	
	/*Part 2*/
	map<string, int> grades;
	grades["Aditya"] = 98;
	grades["Ronnie"] = 96;
	
	/* To find Aditya's grade*/
	if(grades.find("Aditya") != grades.end()) {
		cout<< "Aditya: " << grades["Aditya"] <<endl;
	} else {
		cout<< "Name not found"<<endl;
	}
	
	/*Loop through grades map*/
	double avg;
	int sum=0;
	map<string, int>::iterator it = grades.begin();
	while(it != grades.end()){
		sum += it->second;
		it++;
	}
	
	avg = sum/grades.size();
	cout<< "Average grade is: "<< avg <<endl;
	
	return 0;
}
