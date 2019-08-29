#include <chrono>
#include <memory>
#include <iostream>
#include <list>
#include <random>
using namespace std;
// A example of using weak_ptr as a cache.
const int MAX_SIZE = 10000000;

list<shared_ptr<int>> l;

// find one shared_ptr that points to an int having value val in 
// a list.
// return the found value, else return a nullptr.
shared_ptr<int> find(int val){
    // stores the last accessed value
    static weak_ptr<int> cache;
    // first look into the cache, see does the cache contains the value
    shared_ptr<int> p = cache.lock();
    if (p != nullptr && *p == val){
        return p;
    }

    // otherwise try find in the list
    for (auto elem : l){
        if (*elem == val){
            cache = elem;
            return elem;
        }
    }

    // else the find failed.
    return nullptr;
}

void clear_and_fill_value(){
    l.clear();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1,10);
    // insert a few non-zero random value into the list
    for (int i = 0; i < MAX_SIZE; i++){
        l.emplace_back(make_shared<int>(dis(gen)));
    }
    // insert a 0 in the middle
    l.emplace_back(make_shared<int>(0));
    // more non-zero value after.
    for (int i = 0; i < MAX_SIZE; i++){
        l.emplace_back(make_shared<int>(dis(gen)));
    }
}

int main(){
    clear_and_fill_value();
    
    {
    // first time lookup: need to traverse whole list
    auto start = std::chrono::system_clock::now();
    auto tryFind = find(0);
    auto end = std::chrono::system_clock::now();
    cout << "Time for first lookup:" << (end - start).count() << endl;
    
    // second time lookup: no need to traverse whole list
    start = std::chrono::system_clock::now();
    auto tryFindAgain = find(0);
    end = std::chrono::system_clock::now();
    cout << "Time for second lookup:" << (end - start).count() << endl;
    } // tryFind, tryFindAgain goes out of scope here

    clear_and_fill_value();

    // the orignal value is gone (i.e. weak_ptr::lock() returns nullptr);
    // need to traverse the whole list again
    auto start = std::chrono::system_clock::now();
    auto tryFindAThirdTime = find(0);
    auto end = std::chrono::system_clock::now();
    cout << "Time for third lookup:" << (end - start).count() << endl;


}
