#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {

unordered_map<string, int>* mp = new unordered_map<string, int>;
pair<string, int> p("Babu", 2);
mp->insert(p);


std::cout << "Hello world!" << std::endl;
return 0;
}
