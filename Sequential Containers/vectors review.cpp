#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> numbers1;
	vector<int> numbers(10); // this is dynamic and not limited to size 10
	for(int i=1; i <12; i++) {
		numbers.push_back(i);
	}

	int sum=0;
	for(int i=1; i<numbers.size(); i++) {
		sum += numbers[i];
	}

	cout<<"the total is: "<< sum <<endl;
	return 0;
}