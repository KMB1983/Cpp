#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

    using weighted_pair = std::pair<int, double>;
    using my_container = std::vector<weighted_pair>;

    auto cmp = [](const weighted_pair& e1, const weighted_pair& e2){ return e1.second < e2.second;};
    weighted_pair p1={1, 1.2};
    weighted_pair p2={2, 2.2};
    weighted_pair p3={0, 3.142};
    weighted_pair p4={5, 0.142};

    cout << p1.first << " - " << p1.second << endl;
    if (cmp(p1, p2)) {
        cout << "first is smaller\n";
    }

    // priority_queue<Type, container, comparison>
    std::priority_queue<weighted_pair, my_container, decltype(cmp)> q(cmp);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);


    while(!q.empty()) {

        const auto& p = q.top();
        cout << p.first << ": " << p.second << endl;
        q.pop();
    }


    return 0;
}
