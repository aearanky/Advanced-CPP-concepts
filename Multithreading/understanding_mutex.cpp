#include <iostream>
#include <thread> 
#include <map>
#include <string>
#include <mutex>

std::map<std::string, std::string> my_map;
std::mutex mutex_my_map;

// A callable function
void foo(std::string key, std::string value) 
{   
    // protect the MAP (resource) by reserving a mutex hold on it
    std::lock_guard<std::mutex> guard(mutex_my_map);
    
    //insert the key and value fields into the map 
    my_map.insert(std::pair<std::string, std::string>(key, value));
    
    //mutex leaves grip of the MAP as the lock_guard goes out of scope at this point
}

int main()
{
    std::thread t1(&foo, "human_one", "Aditya");
    std::thread t2(&foo, "human_two", "Prajakta");

    t1.join();
    t2.join();
    
    //safe to access the map after joining the threads
    for(const auto& pair: my_map)  //access by const reference
        std::cout<<pair.first<<": "<<pair.second<<std::endl;
    return 0;
}
