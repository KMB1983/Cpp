#include <iostream>
#include <istream>
#include <fstream>
#include <memory>
#include <map>
#include <vector>
#include "boost/lexical_cast.hpp"
#include <gtest/gtest.h>

using namespace std;
using namespace boost;

class Database{
public:
    virtual int getPopulation(const std::string& name) = 0;
};

class DummyDatabase: public Database{
    map<std::string, int> capitals;
public:
    DummyDatabase() {
        // fill it with fixed values
        capitals["alpha"] = 1;
        capitals["beta"] = 2;
        capitals["gamma"] = 3;
    }
    int getPopulation(const std::string & name) override {
        return capitals[name];
    }
};

struct ConfigurableRecordFinder{
    Database& db;
    ConfigurableRecordFinder(Database &db): db(db) {};

    int totalPopulation(std::vector<std::string> names) {
        int res{0};
        for (auto name: names){
            res+= db.getPopulation(name);
        }
        return res;
    }

};

class SingletonDB: public Database{
private:
    std::map<string, int> capitals;

    SingletonDB() {
        std::cout << "Loadind data\n";
        ifstream ifs("capitals.txt");
        if (ifs.good()) {
            string s1, s2;
            while (getline(ifs, s1)) {
                getline(ifs, s2);
                int population = boost::lexical_cast<int>(s2);
                capitals[s1] = population;
            }
        }
        ifs.close();
    }
public:
    //diable copy contructor and assignmnent operator
    SingletonDB(SingletonDB const &) = delete;
    void operator=(SingletonDB const&) = delete;

    static SingletonDB& get() {
        static SingletonDB db;
        return db;
    }

    int getPopulation(const std::string& name) override {
        return capitals[name];
    }

    void Print() {
    for (auto &el: capitals) {
        cout << el.first << ": " << el.second << "\n";
    }
    }
};

int main() {

    cout << SingletonDB::get().getPopulation("London");
    //SingletonDB singleton;
    //singleton.Print();
    return 0;
}
