#include <iostream>
#include <string>

using namespace std;

struct A {
    int a, b;
    A(int i, int j) {
        a = i;
        b = j;
        cout<<"A's constructor called"<<endl;
    }
};

struct B {
    string c;
    int d;
    B(string i, int j) {
        c = i;
        d = j;
        cout<<"B's constructor called"<<endl;
    }
};

struct derived_C : A, B {
    int e, f;
    derived_C(int p, int q, string str, int t, int u, int v ) : A (p, q), B (str, t) {
        e = u;
        f = v;
        cout<<"derived_C's constructor called"<<endl;
    }
}; 

int main()
{
    derived_C myObj(1, 2, "yo mister", 4, 5, 6);
    cout<<myObj.a << " " << myObj.b << " " <<myObj.c << " " << myObj.d << " " << myObj.e << " " << myObj.f << " ";
    return 0;
}
