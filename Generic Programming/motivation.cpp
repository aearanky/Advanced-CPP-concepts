// When we need to do a task irrespective of the data type

#include<iostream>
#include<string>

using namespace std;

void display(int arr[], int size) {
	for (int i=0; i<size; i++) {
		cout<< arr[i]<<" ";
	}
	cout<<endl;
}

void displayStr(string arr[], int size) {
	for (int i=0; i<size; i++) {
		cout<< arr[i]<<" ";
	}
	cout<<endl;

}

int main() {

	const int size = 10;
	int numbers[size];

	for(int i=0; i<size; i++) {
		numbers[i] = i+1;
	}

	display(numbers, size);

	string names[] = {
		"a","b","c","d","e","f","g","h","i","j"
	};

	displayStr(names, size);

	return 0;
}
