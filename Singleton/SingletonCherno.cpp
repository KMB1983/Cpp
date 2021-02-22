#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

class Singleton{
private:
    std::vector<double> numbers_;

    static mt19937 mt; //starting engine;
    static bernoulli_distribution bdist;

    Singleton(){
        std::cout << "Making new singleton instance\n";
    };
    static Singleton m_Instance;

    static Singleton& get() {
        static Singleton instance;
        return instance;
    }

public:
    Singleton(const Singleton& ) = delete;
    static Singleton& getInstance() {
        return m_Instance;
    }
    void genNumber() {
        numbers_.push_back(bdist(mt));
    }
    void Print() {
        for (const auto &val: numbers_) {
            cout << val << " ";
        }
    }
};

bernoulli_distribution Singleton::bdist(0.5);
mt19937 Singleton::mt;
Singleton Singleton::m_Instance;

int main() {

    Singleton::getInstance().genNumber();
    cout << "Do some stuff here\n";
    for (int i=0; i!=10; i++) {
        Singleton::getInstance().genNumber();
    }

    Singleton::getInstance().Print();

    //Singleton new_s = Singleton::getInstance(); //must be disable assignment


    return 0;
}

