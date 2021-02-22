#include <iostream>
#include <string>
#include <ostream>
#include <sstream>
#include <istream>
#include <memory>
#include "boost/serialization/serialization.hpp"
#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"

using namespace std;
using namespace boost;

struct Address{
    string street;
    string city;
    int suite;

    Address() {};

    Address(const string& street, const string & city, const int& suite):
        city(city), street(street), suite(suite){};

    friend ostream& operator<<(ostream& os, const Address& a){
        os << "street: " << a.street << ", City: " << a.city << ", suite: " << a.suite<< std::endl;
        return os;
    }

private:
    friend class boost::serialization::access;

    template<class archive>
    void serialize(archive& ar, const unsigned version) {
        ar& street;
        ar& city;
        ar& suite;
    }
};

struct Contact{
    string name;
    Address* address;

    Contact(): name(nullptr), address(nullptr){};
    Contact(const string& name, Address* address): name(name), address(address){};
    Contact(const Contact& other) {
        name = other.name;
        address = new Address{
            other.address->street,
            other.address->city,
            other.address->suite};
    };
    ~Contact() { delete address;}
    friend ostream& operator<<(ostream& os, const Contact& c) {
        os << "[CONTACT]: " << c.name << ", " << c.address->street << ", " << c.address->city << ", " << c.address->suite << "\n";
    }
private:
    friend class boost::serialization::access;

    template<class archive>
    void serialize(archive& ar, const unsigned version) {
        ar& name;
        ar& address; // we don't have to use pointer, boost will find out
    }
};

struct EmployeeFactory{
    static std::unique_ptr<Contact> newEmployer(const std::string &name, int suite){
        Contact p{"", new Address{"Alwyne place", "London", NULL}};
        return new_employee(name, suite, p);
    }

private:
    static std::unique_ptr<Contact> new_employee(const std::string& name,
                                                  const int suite,
                                                  const Contact& prototype)
    {
        auto result = std::make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};


int main() {

    auto clone = [](const Contact& contact) {
        ostringstream oss;
        boost::archive::text_oarchive ao(oss);
        ao<<contact;
        string s = oss.str();
        std::cout << s << std::endl;

        istringstream iss(s);
        boost::archive::text_iarchive ai(iss);
        Contact result;
        ai>>result;
        return result;
    };

    auto Babu = EmployeeFactory::newEmployer("Babu", 1234);
    auto Kaja = clone(*Babu);


    Address address("Alwyne place", "London" , 123);
    std::cout << address;

    Contact contact();
    Contact p1{"babu", &address};
    std::cout << p1.address->street << "\n\n";

    Contact proto{"", new Address{"Belidlo", "Praha", NULL}};
    std::cout << proto;

    auto John = EmployeeFactory::newEmployer("John", 1234);
    std::cout << *John;
    return 0;
}
