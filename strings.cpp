#include <iostream>
#include <string>

using namespace std;

int main() {

    string s1{"Hello  "}; // both options: {} or ()
    string s2;
    s2 = " Babu";
    cout << s1.size(); // count spaces
    string s3 = s1 + s2;
    cout << s3 << endl;
    cout << &s1 << endl;
    s1 += s2;
    cout << s1 << ", " << &s1 << endl; // keep address
    auto s = s1.begin(); // adrres of first character position: 'H'
    cout << *s;

    return 0;
}
