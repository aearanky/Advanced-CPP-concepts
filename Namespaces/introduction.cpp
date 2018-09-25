#include <iostream>

using namespace std;

/*Namespaces can include variables, functions and classes*/
namespace firstNums {
	int num1 = 10;
	int num2 = 12;
}

namespace secondNums {
	int num1 = 1;
	int num2 = 2;
}

namespace minMax {
	int min(int num1, int num2) {
		if(num1 < num2) return num1;
		else return num2;
	}
	
	int max(int num1, int num2) {
		if(num1 > num2) return num1;
		else return num2;
	}
}

namespace People {
	class Person{
		private:
		 string name;
		 string sex;
		 
		public:
			Person(string n, string x) {
				name = n;
				sex  = x;
			}
			
			string get() {
				return name + ", " + sex;
			}
	};
}

int main() {

	cout<<"num1 in firstNums: " << firstNums::num1 <<endl;
	cout<<"num1 in secondNums: " << secondNums::num1 <<endl;
	
	cout<<"num2 in firstNums: " << firstNums::num2 <<endl;
	cout<<"num2 in secondNums: " << secondNums::num2 <<endl;
	
	/* Namespaces are block scoped*/
	{
		using namespace firstNums;
		cout<<"num1 in firstNums: " << firstNums::num1 <<endl;
		cout<<"num2 in firstNums: " << firstNums::num2 <<endl;
	}
	
	{
		using namespace secondNums;
		cout<<"num1 in secondNums: " << secondNums::num1 <<endl;
		cout<<"num2 in secondNums: " << secondNums::num2 <<endl;
	}
	
	{
		using namespace minMax;
		using namespace People;
		
		int a,b;
		
		cout<<"Enter a number: ";
		cin >> a;
		
		cout<<"Enter another number: ";
		cin >> b;
		
		cout<<"Smaller of the 2 numbers is: " << min(a,b)<<endl;
		cout<<"Larger of the 2 numbers is: " << max(a,b)<<endl;
		
	
		Person person1("Aditya", "M");
		cout<< "Person Details: "<<person1.get() <<endl;
	}
	
	return 0;
}

