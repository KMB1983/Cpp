#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Neuron;
// CRTP pattern - search for this name will explain casting
template<typename Self>
struct SomeNeuron{
    template<typename T> void connect_to(T& other){
        for (Neuron& from: *static_cast<Self*>(this)){
             for (Neuron& to: other) {
                from.out.push_back(&to);
                to.in.push_back(&from);
             }
        }
    }
};

// note: template of base is derived class
struct Neuron: SomeNeuron<Neuron>{
    std::vector<Neuron*> in, out;
    unsigned int id;

    Neuron() {
        std::cout << "calling ctor\n";
        static unsigned int id{0};
        this->id = id++;
    }

    Neuron* begin(){ return this;}
    Neuron* end() { return this + 1;}

    friend ostream& operator<<(ostream& os, const Neuron& obj){
        for (Neuron* n: obj.in) {
            os << "f[" << n->id << "] -> [" << obj.id << "]/n";
        }
        for (Neuron* n: obj.out) {
            os << "s[" << obj.id << "] <-- [" << n->id << "]\n";
        }
        return os;
    }
};

//unsigned int Neuron::id = 0;

int main() {

    Neuron n1, n2;
    std::cout << n1.id << std::endl;
    std::cout << n2.id << std::endl;

    n1.connect_to(n2);
    cout << n1;
    return 0;
}
