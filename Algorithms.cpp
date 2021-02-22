#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class IsShorter{
    //this is functor, can be used in algorithms
public:
    bool operator()(const string& lhs, const string& rhs) {
        return lhs.size() <= rhs.size();
        }
};

class IsOdd{
public:
    bool operator()(int n) { return !(n%2);}
};

class GreaterThan{
private:
    int _n;
public:
    int n;
    GreaterThan(int n): _n(n){};
    bool operator()(const string& s) {
        return s.size() > _n;
    }
};

template<typename T> void PrintVector(const vector<T>& v) {
    for (auto &val: v) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {

    int val{5};

    vector<int> v{1, 2, 5, 4, 3, 1, 3, 2, 6, 4};
    vector<string> vs{"Hello", "Bouran", "Karolina", "Mariana", "Matej"};
    string s{"Hello Babu"};

    PrintVector(vs);
    sort(vs.begin(), vs.end(), IsShorter());
    PrintVector(vs);

    val = 7;
    //auto it_greater = find_if(vs.begin(), vs.end(), GreaterThan(val));
    auto _lambda_greater = [val](const string& s){ return s.size() >= val;};
    auto it_greater = find_if(vs.begin(), vs.end(), _lambda_greater);
    cout << "Greater than " << val << " is: " << *it_greater << endl;

    PrintVector(v);
    val = 1;
    int counter = std::count(v.cbegin(), v.cend(), val);
    cout << val << ": " << counter << "times\n";
    //count if need predicate
    //auto nOdds = count_if(v.cbegin(), v.cend(), IsOdd());
    auto nOdds = count_if(v.cbegin(), v.cend(), [](const int n){ return !(n%2);});
    cout << "N_odds = " << nOdds << endl;


    auto it = find(s.begin(), s.end(), 'B');
    if (it != s.end()) {
        cout << *it << endl;
    }
    *it = 'W';
    cout << s;

    return 0;
}
