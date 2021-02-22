#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;

template <typename T>
void printVector(const vector<T>& v) {
    for (auto& val: v) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {

    mt19937 mt; // start engine
    uniform_int_distribution<int> uniform(0,10);
    for (size_t i=0; i!=20; i++) {
        cout << uniform(mt) << " ";
    }
    cout << endl;

    uniform_real_distribution<double> U_01(0,1);
    for (size_t i=0; i!=20; i++) {
        cout << U_01(mt) << " ";
    }
    cout << endl;

    // shuffling data
    static mt19937 mt2;
    vector<int> v{1,2,3,4,5,6,7,8,9};

    for (size_t i = 0; i!=5; i++) {
        shuffle(v.begin(), v.end(), mt2);
        printVector(v);

        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    static bernoulli_distribution bdist(0.5);
    cout << bdist(mt2) << " " << bdist(mt2) << endl;




    return 0;

}
