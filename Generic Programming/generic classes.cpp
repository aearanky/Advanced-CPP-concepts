#include <iostream>

using namespace std;

template <typename T>
class Stack {
	private:
		T dataStore[100];
		int top;
	public:
		Stack(){
			top=-1;
		}

		void push(T num){
			++top;
			dataStore[top] = num;
		}

		T pop(){
			T val = dataStore[top];
			dataStore[top]=0;
			--top;
			return val;
		}

		T peek(){
			T val = dataStore[top];
			return val;
		}

};


// This is called class specilization
// We used this tecnique to handle datastore[top] in pop()
// as strings would require a different treatment as compared to 
// number types like int, float, double etc.. 
template<>
class Stack<string> {
	private:
		string dataStore[100];
		int top;
	public:
		Stack(){
			top=-1;
		}

		void push(string val){
			++top;
			dataStore[top] = val;
		}

		string pop(){
			string val = dataStore[top];
			dataStore[top]="";
			--top;
			return val;
		}

		string peek(){
			string val = dataStore[top];
			return val;
		}
};

int main() {

	Stack<double> numbers;
	numbers.push(10);
	numbers.push(12);

	cout<<numbers.peek()<<endl;
	numbers.pop();
	cout<<numbers.peek()<<endl;

	Stack<string> names;
	names.push("Aditya");
	names.push("Korey");

	cout<<names.peek()<<endl;
	names.pop();
	cout<<names.peek()<<endl;

	return 0;
}