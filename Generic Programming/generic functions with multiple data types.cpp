#include <iostream>

using namespace std;

template <typename T, typename U>
T max(T arg1, U arg2){
	return (arg1 > arg2) ? arg1 : arg2;
}

int main() {

	double num1 = 35.55;
	int num2 = 12;
	
	// Result of this one will be of type double as the first argument is of type double
	cout<<max(num1, num2)<<endl;

	// Result of this one will be of type int as the first argument is of type int
	cout<<max(num2, num1)<<endl;

	int num3 =130;

	// Result of this one will be of type double as the first argument is of type double
	// even though the larger number is of type int 
	cout<<max(num1, num3)<<endl;

	return 0;
}