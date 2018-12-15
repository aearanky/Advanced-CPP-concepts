#include <iostream>
#include <thread> 

// A callable function
void foo(int Z) 
{
    for(auto x=0; x<Z; x++)
        std::cout<<"Calling through function pointer"<<std::endl;
}

// A callable object 
class thread_obj { 
public: 
    void operator()(int x) 
    { 
        for (int i = 0; i < x; i++) 
            std::cout << "Thread using function"
                  " object as callable"<<std::endl; 
    }}; 

int main()
{
    std::thread t1(&foo, 2);
    std::thread t2(thread_obj(), 2);

    //create a lambda expression
    auto f = [](int Z){
         for (int i = 0; i < Z; i++) 
            std::cout << "Thread using lambda"
                  " expression as callable"<<std::endl; 
    };
    
    std::thread t3(f, 2);
    
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
