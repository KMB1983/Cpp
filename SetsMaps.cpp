#include <iostream>
#include <set>
#include <map>

#include <string>
#include <algorithm>

#include "Timer.h"

using namespace std;

template<typename T> void PrintContainer(const std::set<T>& v){
    for (auto &val: v) {
        cout << val << " - ";
    }
    cout << endl;
}
template<typename K, typename V> void printMap(const std::map<K,V>& m) {
    for (auto &p: m) {
        cout << p.first << ": " << p.second << endl;
    }
    cout << endl;
}
// C++ 17
template<typename K, typename V> void printMap2(const std::map<K,V>& m) {
    for (auto& [k, v]: m) {
        cout << k << ": " << v << endl;
    }
}

int main() {

    set<int> s{1,3,5};

    // insert return std::pair<bool, T> first is value and second is bool - success or failed insert
    auto ptr = s.insert(6);
    if (ptr.second) {
        cout << "added " << (*ptr.first) << endl;
    }
    PrintContainer(s);

    map<string, int> score;
    score.insert(make_pair("Babu", 101));
    score.insert({"Kaja", 102}); // C++11

    string name{"Kaja"}; // check whtere ky exists
    if (score.count(name)) {
        cout << name << ": found \n";
    }

    auto _ptr = score.find(name);
    if (_ptr != score.end()) {
        cout << _ptr->first << ": " << _ptr->second << endl;
    }

    printMap2(score);
    cout << "=============================\n";

    multimap<string, int> id {{"Babu", 1}, {"Kaja", 2}, {"Maja", 3}, {"Babu", 10}, {"Kaja", 20}};
    auto start = id.lower_bound("Babu");
    auto end = id.upper_bound("Babu");

    for (auto it = start; it!= end; it++) {
        cout << it->first << ": " << it->second << endl;
    }

    // another way of seraching: equal -> returns a pair: start and end
    auto eq = id.equal_range("Babu");
    for (auto it= eq.first; it!=eq.second; ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << "================================\n";
    auto _find_ptr = find_if(start, end, [](pair<string, int> p){ return p.second == 10;});
    if (_find_ptr != end) {
        cout << "Found \n" << _find_ptr->first << ": " << _find_ptr->second << endl;

    }



    {
        Timer timer;
    }


    return 0;

}


