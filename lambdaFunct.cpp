
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

auto GenerateSalary(double rate) {
    // return lambda function
    return [rate](double salary){ return rate * salary;};
}

void PrintVector(const vector<int>& v) {
    for (auto &val: v) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {

    auto salary_gen = GenerateSalary(1.1); // functor
    cout << salary_gen(1000) << endl;

    //dynamically alocated pair
    std::pair<string, string>* p = new pair<string, string>("Hello", "Babu");
    cout << p->first << " - " << p->second << endl;

   pair<int, int> p2 = minmax({1,3,5});
   cout << "min: " << p2.first << ", max: " << p2.second << endl;

   vector<int> v{12, 5, 1,3,5,2,6,7,9,6};
   auto min_elem = min_element(v.begin(), v.end());
   cout << "min: " << *min_elem << endl;

   //min max
   auto minmax_elem = minmax_element(v.begin(), v.end());
   cout << "min: " << *minmax_elem.first << ", max: " << *minmax_elem.second << endl;

   vector<int> v1(10);
   iota(v1.begin(), v1.end(), 1);
   PrintVector(v1);

    auto sum = accumulate(v1.begin(), v1.end(), 0);
    cout << "sum = " << sum << endl;

    auto sum_even = accumulate(v1.begin(), v1.end(), 0, [](int sum, int n){ return n%2 ? sum + n : sum;});
    cout << "sum even: " << sum_even << endl;

    vector<int> v3(10, 1);
    vector<int> v4(10, 1);
    iota(v4.begin(), v4.end(), 1);
    PrintVector(v3);
    PrintVector(v4);
    int ip = inner_product(v3.begin(), v3.end(), v4.begin(), 0);
    cout << "inner product: " << ip << endl;


    return 0;
}
