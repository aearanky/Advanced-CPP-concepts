#include <iostream>

using namespace std;

int main() {

	cout<<"hello"<<endl; //Hello streamed to cout
	cout.put('h');
	cout.put('e').put('\n');
	cout<<"hello"<<endl<<flush; //Hello 'flushed' after it was streamed
	cout<<"hello"<<endl<<ends;

	return 0;
}