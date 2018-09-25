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

		double grossPay(int hours){
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

		double grossPay(int hours){
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

	// The problem here is the compiler is not looking at the type of the `mgr1` object 
	// but is looking at the type of the pointer empPtr and hence is calling gross Pay from employee
	empPtr = &mgr1;
	cout<< "Name:" << empPtr->getName() << endl;
	cout<< "Pay:" << empPtr->grossPay(40) << endl;

	return 0;
}
