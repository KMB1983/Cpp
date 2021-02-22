#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <functional> // for plus minus

using namespace std;

template <typename T>
void printVector(const vector<T>& v) {
    for (auto& val: v) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {

    vector<int> v1{1,2,3,4,5,6};
    vector<int> v2;
    v2.resize(v1.size());
    // copy first n - 2 elements
    std::copy(v1.begin(), v1.end()-2, v2.begin());
    printVector(v2);

    // if donty know the size ahead use back_inserter
    vector<int> v3;
    std::copy(v1.begin(), v1.end(), back_inserter(v3));
    printVector(v3);

    //copy  n elements
    vector<int> v4;
    copy_n(v1.begin(), 3, back_inserter(v4));
    printVector(v4);

    // conditional copy
    vector<int> v5;
    copy_if(v1.begin(), v1.end(), back_inserter(v5),[](int n) {return n%2==0;});
    printVector(v5);

    vector<double> v6;
    std::transform(v1.begin(), v1.end(), back_inserter(v6), [](int n){ return std::sqrt(n);});
    printVector(v6);

    // aritmetic operation two vetors
    vector<int> v7(10, 1);
    vector<int> v8 = v7;
    vector<int> v9;
    iota(v8.begin(), v8.end(), 0);
    if (v7.size() == v8.size()) {
        //std::transform(v7.begin(), v7.end(), v8.begin(), back_inserter(v9), [](int n1, int n2){ return n1-n2;});
        std::transform(v7.begin(), v7.end(), v8.begin(), back_inserter(v9), std::minus<int>());
        //std::transform(v7.begin(), v7.end(), v8.begin(), back_inserter(v9), std::greater<int>()); //  check more options
        cout << "===============\n";
        printVector(v7);
        printVector(v8);
        printVector(v9);

    }

    // remove is more tricky - move to invalid position but do not erase
    vector<int> v10{1,2,3,4,3,2,1,3,2,1};
    auto ptr_rm = remove(v10.begin(), v10.end(), 1);
    v10.erase(ptr_rm, v10.end());
    printVector(v10);

    // get unique values, removes only adjacent values, must sort first
    vector<int> v11{1,2,3,4,5,6,7,4,3,2,3,5};
    sort(v11.begin(), v11.end());
    auto _rmptr = unique(v11.begin(), v11.end());
    v11.erase(_rmptr, v11.end());
    printVector(v11);

    return 0;
}
