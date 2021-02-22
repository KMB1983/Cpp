#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <math.h>



using namespace std;

void printVector(const vector<int>& v) {
    for (auto &val: v) {
        cout << val << " ";
    }
    cout << endl;
}

template<typename T> double L2calc(const vector<T>& v) {
    double val = std::sqrt(std::inner_product(v.begin(), v.end(), v.begin(), 0));
    return val;
}


int main() {

    vector<int> v1(3);
    iota(v1.begin(), v1.end(), 1);
    printVector(v1);

    //auto ip = inner_product(v1.begin(), v1.end(), v1.begin(), 0);
    double val = L2calc(v1);
    cout << val << endl;

    vector<int> v2(4); // must know the size before
    fill(v2.begin(), v2.end(), 4);
    printVector(v2);

    vector<int> v3(5);
    fill_n(v3.begin(), v3.size() - 1, 2); // fill all vals but not last with 2
    printVector(v3);

    // fil_n does not have the end() iterator, safe way to fill useing abckj_inserter
    vector<int> v4; // emtpy vector
    fill_n(back_inserter(v4), 5, 10);
    printVector(v4);

    vector<int> v5(10);
    int cnt(0);
    generate(v5.begin(), v5.end(), [&cnt](){return pow(cnt++, 2);});
    printVector(v5);

    vector<int> v6{1,2, 3,5,7,6,4,8};
    // replace all even with zero
    replace_if(v6.begin(), v6.end(), [](int n){ return n%2==0;}, 0);
    printVector(v6);

    string s{"BouRaceK"};
    for_each(s.begin(), s.end(), [](char &c){ c = tolower(c);});
    cout << s << endl;


    return 0;
}

