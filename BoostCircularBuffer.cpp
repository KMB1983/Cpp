#include <iostream>
#include <boost/circular_buffer.hpp>
#include <eigen3/Eigen/Dense>

using namespace std;

int main() {

    boost::circular_buffer<int> cb(3);

    cb.push_back(1);
    cb.push_back(2);
    cb.push_back(3);
    cb.push_back(4);

    while (!cb.empty()) {
        cout << cb.front() << " -> ";
        cb.pop_front();
    }

    return 0;
}
