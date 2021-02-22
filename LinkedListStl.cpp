#include <iostream>
#include <list> // double linked list

using namespace std;

void printList(std::list<int>& l) {
    std::list<int>::const_iterator cit;
    for (cit = l.cbegin(); cit !=l.cend(); cit++) {
        cout<< *cit << " ->";
    }
    cout << endl;
}

int main() {

    list<int> l{1,2,3,4, 5, 3, 4, 5,8, 7};

    printList(l);

    // insert at the front
    auto it = l.begin();
    l.insert(it, 0);
    printList(l);
    //insert after 3;
    while (it != l.end()) {
        if (*it == 3) break;
        it++;
    }
    l.insert(++it, 10);
    printList(l);

    //delete last element
    auto node = l.end();
    node--;
    l.erase(node);
    printList(l);
    // remove node with given value
    l.remove(2);

    // we cannot use generic sort froms stl, there is no ordering, used method instead
    //sort(l.begin(), l.end());
    // unique requires sorting because it removes only adjecent same values
    l.sort();
    l.unique();
    printList(l);

    // merging: again first must sort lists
    list<int> l1{1,2,6,43,7};
    list<int> l2{34,2,1, 5, 6};
    l1.sort();
    l2.sort();
    l1.merge(l2);
    printList(l1);


    return 0;
}
