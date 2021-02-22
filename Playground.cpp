#include <vector>
#include <string>
#include <iostream>

using namespace std;

class MyClass{
public:
    string name;
    int values;
    MyClass(string name="Babu", int val=3): name(name), values(val){}
};


int main() {

    pair<int, int> p(1,2); //
    pair<string, int> p1{"hello",2};
    auto p3 = std::make_pair("Babu", 3);

    MyClass x;

    for (const auto &attr: p1.attributes) {
        std::cout << attr << " ";
    }

    return 0;
}
