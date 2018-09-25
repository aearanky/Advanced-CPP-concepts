#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Employee {
	protected:
		double pay;
		string name;
	public:
		Employee() {
			name = "";
			pay = 0;
		}

		Employee(string Name, double Pay) {
			name = Name;
			pay = Pay;
		}

		void setName(string Name) {
			name = Name;
		}

		string getName() {
			return name;
		}

		void setPay( double payRate) {
			pay = payRate;
		}

		double getSalary() {
			return pay;
		}

		string toString() {
			stringstream stm;
			stm<<name<<": "<<pay;
			return stm.str();
		}

		virtual double grossPay(int hours){
			return pay * hours;
		}
};

class Manager : public Employee {

	private:
		bool salaried;

	public:
		Manager(string Name, double payRate, bool isSalaried) : Employee(Name, payRate) {
			salaried = isSalaried;
		}

		~Manager() {
			//free allocated space
		}

		bool getIsSalaried() {
			return salaried; 
		}

		virtual double grossPay(int hours){   // Making this virtual is not required but recommended
			if(salaried) {
				return pay;	
			} else {
				return pay * hours;
			}
		}

};

int main(){

	Employee emp1("Aditya", 25);
	Manager mgr1("Korey", 1200, true);

	Employee *empPtr;
	empPtr = &emp1;
	cout<< "Name:" << empPtr->getName() << endl;
	cout<< "Pay:" << empPtr->grossPay(40) << endl;

	// The compiler is now going to see grosspay() as a virtual function 
	// and will fire the function depending on the object
	empPtr = &mgr1;
	cout<< "Name:" << empPtr->getName() << endl;
	cout<< "Pay:" << empPtr->grossPay(40) << endl;


	// It is necessary to make the vector type employee pointer to make sure the compiler understands
	vector<Employee*> employees;
	employees.push_back(&emp1);
	employees.push_back(&mgr1);

	for(int i=0; i<employees.size(); i++) {
		cout<< "Name:" << employees[i]->getName() << endl;
		cout<< "Pay:" << employees[i]->grossPay(40) << endl;
	}

	return 0;
}
