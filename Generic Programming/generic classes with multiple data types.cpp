#include <iostream>
#include <string>
#include<vector>

using namespace std;

template<class T, class U>
class CMap {
	private:
		vector<T> keys;
		vector<U> values;
	public:
		void insert(T key, U value) {
			keys.push_back(key);
			values.push_back(value);
		}

		void get(int n) {
			cout<< keys[n] <<":"<<values[n]<<endl;
		}
};

int main() {
	CMap<string, int> map;
	map.insert("aditya", 1);
	map.get(0);
	return 0;
}