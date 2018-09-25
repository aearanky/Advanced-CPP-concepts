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

	vector<Employee> emps;
	emps.push_back(emp1);
	emps.push_back(mgr1);

	// this will end up calling gross pay only from the base class => fails at polymorphism
	for(int i=0; i<emps.size(); i++) {
		cout << emps[i].grossPay(40) << endl;
	}

	return 0;
}
