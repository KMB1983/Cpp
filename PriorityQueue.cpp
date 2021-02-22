#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class PriorityQueue{
private:
    vector<T> pq;

public:
    PriorityQueue() {}

    bool isEmpty() { return pq.size() == 0;}
    int getSize() { return pq.size();}
    T getMin() {
        if (isEmpty()) {
            return 0;
        }
        return pq.at(0);
    }

    void insert(T elem) {
        pq.push_back(elem);
        int cI = pq.size() - 1;

        while (cI>=0) {
            int pI = (cI - 1) / 2;
            if (pq[pI] > pq[cI]) {
                std::swap(pq[pI], pq[cI]);
                cI = pI;
            } else {
                break;
            }
        }
    }

    T removeMin() {
        if (isEmpty()) { return 0;}

        T ans = pq.at(0);
        std::swap(pq[0], pq[pq.size()-1]);
        pq.pop_back();

        int pI = 0;
        while (true) {
            int lci = 2*pI + 1;
            int rci = 2*pI + 2;
            int minIndx = pI;
            if (lci<pq.size() && pq[lci]<pq[pI]) {
                minIndx = lci;
            }
            if (rci<pq.size() && pq[rci] < pq[pI]) {
                minIndx = rci;
            }

            if (pI == minIndx) { break;}
            std::swap(pq[minIndx], pq[pI]);
            pI = minIndx;

        }

        return ans;
    }

    void Print() {
        for (auto val: pq) {
            cout << val << " -> ";
        }
        cout << endl;
    }

};


int main() {

    PriorityQueue<int> pq;
    cout << "size: " << pq.getSize() << ", " << pq.getMin();
    pq.insert(10);
    pq.insert(1);
    pq.insert(5);
    pq.insert(7);
    pq.insert(15);
    cout << "size: " << pq.getSize() << ", " << pq.getMin() << endl;
    pq.Print();
    cout << "min = " << pq.removeMin() << endl;
    pq.Print();
    cout << "min = " << pq.removeMin() << endl;
    pq.Print();

    return 0;
}
