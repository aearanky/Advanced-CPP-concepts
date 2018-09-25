#include<iostream>
#include<stdexcept>

using namespace std;

class DivideByZero: public runtime_error {
	public:
		DivideByZero(): runtime_error("Divide by zero exception") {};
};

double quotient (double numer, double denom) {
	if(denom == 0) {
		throw DivideByZero();
	} else {
		return numer/denom;
	}
}

int main() {

	double numer, denom, ratio;
	cout<<"Enter a numerator: "; cin>> numer;
	cout<<"Enter a denominator: "; cin>> denom;
	try {
	
		ratio = quotient(numer,denom);
		cout<<"The result is: "<< ratio << endl;
	
	} catch (DivideByZero &exception) {
		cout << exception.what() <<endl;
	}

	return 0;
}