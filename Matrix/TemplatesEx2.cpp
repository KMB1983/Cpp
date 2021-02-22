#include <iostream>

using namespace std;

template<typename T> class Base{
protected:
    T x_;
public:
    Base() = default;
    Base(T x): x_(x){}
    T getX();
    virtual void  Display() = 0;
};

template<typename T>
T Base<T>::getX() { return x_;}

template<typename T>
class Derived: Base<T> {
private:
    T y_;
public:
    Derived(T y, T x): Base<T>{x}, y_(y){}
    void Display() override;
} ;

template<typename T>
void Derived<T>::Display() {
        cout << "Hello from Derived\n";
        cout << Base<T>::getX() << " " << y_ << std::endl;
    }

int main() {

    Derived<int> d(20, 10);
    d.Display();

    return 0;
}

