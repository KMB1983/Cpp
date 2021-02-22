#include <iostream>
#include <array>
#include <vector>

using namespace std;

int Fib(int n) {
    static std::vector<int> F(n, -1);
    if (n<=1) {
        F[n] = n;
        return n;
    }
        if (F[n-2]== -1) {
            F[n-2] = Fib(n-2);
        }
        if (F[n-1]== -1) {
            F[n-1] = Fib(n-1);
        }

        return F[n-2] + F[n-1];

}

int main() {

    cout << Fib(5);

    return 0;

}
