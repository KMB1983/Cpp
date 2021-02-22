#include <iostream>
#include <cmath>
//#include "bits/stdc++.h"

using namespace std;

double exp_faster(double x, int n) {
    static double s{1};

    if (n<=0) return s;
    s = 1 + x * s / n;
    return exp_faster(x, n-1);

}

double _exp(double x, int n){
    static double pow{1};
    static int fact{1};
    double res = 0;

    if (n <= 0) return 1;
    res = _exp(x, n-1);
    pow *= x;
    fact *= n;
    return res + pow / fact;
}
int main() {

    double x = 0.5;
    cout << _exp(x, 10) << ", "<< exp(x) << ", exp_faster " << exp_faster(x, 10) << endl;
    return 0;

}
