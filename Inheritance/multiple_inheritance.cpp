
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
    
    ~A() {
        cout << "A's destructor called"<<endl;
    }
    
    int get_a() {
        return a;
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
    
    ~B() {
        cout << "B's destructor called"<<endl;
    }
};

struct C : A, B {
    int e, f;
    C(int p, int q, string str, int t, int u, int v ) : A (p, q), B (str, t) {
        e = u;
        f = v;
        cout<<"C's constructor called"<<endl;
    }
    
    ~C() {
        cout << "C's destructor called"<<endl;
    }
};

struct D : A {
    
    A* an_A_obj_pointer;
    
    D(int i, int j, A* some_pointer_to_A): A(i,j) {
        an_A_obj_pointer = some_pointer_to_A;
        cout << "D's constructor called"<<endl;
    }
    
    ~D() {
        cout << "D's destructor called"<<endl;
    }
};

int main()
{
    C myObj(1, 2, "yo mister", 4, 5, 6);
    cout<<myObj.a << " " << myObj.b << " " <<myObj.c << " " << myObj.d << " " << myObj.e << " " << myObj.f << " " <<endl;
    
    D myDobj(7,8, new A(7,8));
    cout<<myDobj.an_A_obj_pointer->get_a() << " " << myDobj.an_A_obj_pointer->b<<endl;
    
    return 0;
}

/*Expected Output:
A's constructor called                                                                                                            
B's constructor called                                                                                                            
C's constructor called                                                                                                            
1 2 yo mister 4 5 6                                                                                                               
A's constructor called                                                                                                            
A's constructor called                                                                                                            
D's constructor called                                                                                                            
7 8

D's destructor called                                                                                                             
A's destructor called                                                                                                             
C's destructor called                                                                                                             
B's destructor called                                                                                                             
A's destructor called 
*/
