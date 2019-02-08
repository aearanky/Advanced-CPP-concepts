// mutex example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex


class myClass{

public:
    int i;
    int n;
    std::mutex mtx;   // mutex for critical section
    
    myClass(){
        i = 0;
        n = 1500;
    }
    
    void runThread() {
        std::thread th1 (&myClass::print_block, this, '*');
        std::thread th2 (&myClass::print_block, this, '$');
        
        th1.join();
        th2.join();
    }

    void print_block (char c) {
    
        // critical section (exclusive access to std::cout signaled by locking mtx):
        mtx.lock();
        for (; i<n; ++i) { 
            std::cout << c; 
        }
        std::cout << '\n';
        mtx.unlock();
    }
};

int main ()
{

  myClass m;
  m.runThread();

  return 0;
}
