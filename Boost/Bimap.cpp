#include <iostream>
#include <string>

#include "boost/bimap.hpp"


using namespace std;

typedef boost::bimap<int, std::string> bm_type;

int main() {

    bm_type bm;
    bm.insert(bm_type::value_type(1, "Babu"));
    bm.insert(bm_type::value_type(2, "Kaja"));

    // how to iterate
    for (const auto &b: bm) {
        cout << "left-> " <<b.left << ", right-> " << b.right << endl;;
    }
    for (bm_type::const_iterator iter=bm.begin(); iter!= bm.end(); iter++) {
        cout << "left-> " <<iter->left << ", right-> " << iter->right << endl;;
    }
    //bm.left works as std::map<int, string>
    //bm.right works as map<string, int>
    typedef bm_type::left_map::const_iterator bm_left_type;
    for (bm_left_type iter = bm.left.begin(); iter!= bm.left.end(); iter++) {
        cout << iter->first << " -->  " << iter->second << endl;
    }

    return 0;
}
