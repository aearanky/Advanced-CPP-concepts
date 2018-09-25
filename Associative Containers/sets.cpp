#include <iostream>
#include <set>

using namespace std;
int main() {

	/* Removes the duplicates automatically*/
	set<string> words;
	string word = "";
	
	do {
		cout<<"Enter a word: ";
		cin >> word;
		words.insert(word);
	} while (word != "quit");
	
	set<string>::iterator it = words.begin();
	
	/* Do see how the duplicates are removed */
	while(it != words.end()){
		cout <<*it <<" ";
		++it;
	}
	
	cout<< endl;
	
 return 0;
}
