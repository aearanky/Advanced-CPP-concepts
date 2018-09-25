#include <iostream>
#include <sstream>

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

};

int main(){
	Employee emp1("Aditya", 85000);
	Employee emp2("Rahul Bhatia", 70000);
	cout<<emp1.toString()<<endl;

	Manager mgr1("Korey", 90000, true);
	cout<<mgr1.getName()<<endl;
	cout<<mgr1.getSalary()<<endl;
	cout<<mgr1.getIsSalaried()<<endl;

	return 0;
}
