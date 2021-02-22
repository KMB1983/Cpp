#include <iostream>
#include <string>
#include "boost/bimap.hpp"
#include "boost/flyweight.hpp"
#include "boost/flyweight/key_value.hpp"

using namespace std;
typedef uint32_t key;
typedef boost::bimap<key, std::string> bm_type;


class User{
public:
    User(const string& fname, const string& lname): first_name(add(fname)), last_name(add(lname)) {}

    const string& get_first_name() const {
        return names.left.find(first_name)->second;
    }
    const string& get_last_name() const {
        return names.left.find(last_name)->second;
    }

protected:
    int first_name, last_name;
    static int seed;
    static bm_type names;

    static key add(const string& name){
        auto iter = names.right.find(name);
        if (iter == names.right.end()) {
            // not found add it
            int id = ++seed;
            names.insert(bm_type::value_type(id, name));
            return id;
        }
        return iter->second;
    }

};

int User::seed = 0;
bm_type User::names = {};

// built in boost::flyweight
/*
using namespace boost::flyweights;

class User2{
public:
    flyweight<std::string> first_name;
    User2(const string& fname): first_name(fname) {};
};
*/

int main() {

    User user1("Babu", "Bouran"), user2("Babu", "Bourak");
    cout << user1.get_first_name() <<" " << user1.get_last_name();



    return 0;
}
