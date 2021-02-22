#include <iostream>
#include "bits/stdc++.h"
#include <vector>

using namespace std;

int helper(int n, int *ans) {
    if (n<=1) {return 0;}

    if (ans[n]!=-1) { return ans[n];}

    int y = INT_MAX;
    int z = INT_MAX;
    int x = helper(n-1, ans);
    if (n%2==0) {
        y = helper(n/2, ans);
    }
    if (n%3==0) {
       z = helper(n/3, ans);
    }

    int out = std::min(x, std::min(y, z)) + 1;
    ans[n] = out;
    return out;
}


int minSteps2(int n){
  int *ans = new int[n+1];
  for (size_t i=0; i<=n; i++) {
    ans[i] = -1;
  }
  return helper(n, ans);
}

int minSteps(int n) {
    //base case
    if (n<=1) {return 0;}
    int y = INT_MAX;
    int z = INT_MAX;
    int x = minSteps(n-1);
    if (n%2==0) {
        y = minSteps(n/2);
    }
    if (n%3==0) {
        z = minSteps(n/3);
    }

    int ans = std::min(x, std::min(y, z)) + 1;
    return ans;
}

int main() {

    int num = 10;
    std::cout <<  "Recursion: " << minSteps(num) << ", memo: " << minSteps2(num)<< std::endl;

    return 0;
}
