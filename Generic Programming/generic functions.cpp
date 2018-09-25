// When we need to do a task irrespective of the data type

#include<iostream>
#include<string>

using namespace std;

template <typename T>
void display(T arr[], int size) {
	for (int i=0; i<size; i++) {
		cout<< arr[i]<<" ";
	}
	cout<<endl;
}

template <typename T>
T max(T &arg1, T &arg2) {
	if(arg1 > arg2) {
		return arg1;
	} else {
		return arg2;
	}
}

int main() {

	// Testing the display function
	const int size = 10;
	int numbers[size];

	for(int i=0; i<size; i++) {
		numbers[i] = i+1;
	}

	display(numbers, size);

	string names[] = {
		"a","b","c","d","e","f","g","h","i","j"
	};

	display(names, size);



	// Testing the max function

	int a=12;
	int b=24;
	cout<< max(a,b) <<endl;
	
	double x=2.25;
	double y=0.25;
	cout<< max(x,y) <<endl;

	int *m;
	int *n;

	m = &a;
	n = &b;
	cout<< max(*m,*n) <<endl;


	return 0;
}
