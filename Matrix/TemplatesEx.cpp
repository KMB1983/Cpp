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

template<typename T, typename BaseType>
class Derived: Base<BaseType> {
private:
    T y_;
public:
    Derived(T y, BaseType x): Base<BaseType>{x}, y_(y){}
    void Display() override;
} ;

template<typename T, typename BaseType>
void Derived<T, BaseType>::Display() {
        cout << "Hello from Derived\n";
        cout << Base<BaseType>::getX() << " " << y_ << std::endl;
    }

int main() {

    Derived<int, int> d(20, 10);
    d.Display();

    return 0;
}
