#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student{
private:
    string _name;
    int _id;
public:
    Student(const string& name, const int& id): _name(name), _id(id){};
    Student(const Student& other): _name(other._name), _id(other._id) {}; // copy constructor

    int getId() const {return _id;}
    string getName() const {return _name;}

    void print(ostream& os) const;

    bool operator<(const Student& other) const;
    bool operator>(const Student& other) const;
    bool operator<=(const Student& other) const;
    bool operator>=(const Student& other) const;
    bool operator==(const Student& other) const;
    bool operator!=(const Student& other) const;

};

void Student::print(ostream& os) const{
    os << "Name: " << _name << ", id: " << _id<< "\n";
}

ostream& operator<<(ostream& os, const Student& s) {
    s.print(os);
    return os;
}

bool Student::operator<(const Student& other) const {
    if (this->_id < other._id)
        return true;
    return false;
}

bool Student::operator==(const Student& other) const {
    if (this->_id == other._id)
        return true;
    return false;
}


bool Student::operator!=(const Student& other) const{
    return !(*this == other);
}

bool Student::operator<=(const Student& other) const {
    return *this < other && *this == other;
}

bool Student::operator>(const Student& other) const {
    return !(*this < other || *this == other);
}

bool Student::operator>=(const Student& other) const {
    return *this > other || *this == other;
}


int main() {

    //inserter
    vector<int> v{1,2,3,4,5};
    auto it = inserter(v, v.begin() + 2);
    *it = 0;
    *(++it) = 10;

    for (auto &val: v) {
        cout << val << " ";
    }
    cout << endl;


    Student s1("Babu", 100);
    Student s2("Maja", 101);
    Student s3("Kaja", 100);
    Student s4 = s2;
    s1.print(cout);
    cout << s2 << endl; // both works

    if (s1 == s3) {
        cout << "Same students id!\n";
    }

    if (s1 != s2) {
        cout << "Different students id!\n";
    }

    if (s1 < s2) {
        cout<< s1.getName() << " < " << s2.getName()<<endl;
    }

    if (s2 >= s1) {
        cout<< s1.getName() << " >= " << s2.getName()<<endl;
    }




    return 0;
}
