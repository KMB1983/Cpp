#include <iostream>
#include <string>
#include <vector>
#include <Eigen/Dense>
//#include "/usr/include/eigen3/Eigen/Dense.h

using namespace Eigen;

using namespace std;


int main() {
    vector<pair<string, int>> v;
    std::pair<std::string, int> p("Babu", 1);

    v.push_back(p);
    std:: cout << v.at(0).first << ", " << v.at(0).second << std::endl;

    MatrixXd m(2,2);
    VectorXd v2(2);

    m(0,0) = 1;
    m(1,1) = 1;
    std::cout << m;

return 0;
}
