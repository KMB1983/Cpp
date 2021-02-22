#include <iostream>
#include <memory>


using namespace std;

class Point{
public:
    int x_, y_;
    explicit Point(int x, int y): x_(x), y_(y){}

    friend ostream& operator<<(ostream& os, const Point& obj) {
        os << "[X, Y] = " << obj.x_ << ", " << obj.y_ << endl;
        return os;
    }
};

class Integer{
private:
    int x_;
public:

    Integer() = default;
    explicit Integer(int x): x_(x) {}
    void Print() {
        cout << "X = " << x_ << endl;
    }
};

int main() {

    Integer* x = new Integer{1};
    x->Print()
;
    std::unique_ptr<int> ptr1 = make_unique<int>(2);
    std::shared_ptr<int> ptr2;
    unique_ptr<Point> ptr4 = make_unique<Point>(1,2);
    shared_ptr<Point> ptr5 = make_shared<Point>(1,2);

    cout << *ptr4;
    cout << sizeof(*ptr4) << endl;
    cout << sizeof(*ptr5) << endl;
    cout << sizeof(ptr4) << endl;
    cout << sizeof(ptr5) << endl;

    cout << "==============\n";
    cout << sizeof(ptr1)<<endl;
    cout << sizeof(ptr2)<<endl;
    cout << *ptr1 << endl;
    cout << ptr1.get() << endl;
    auto ptr3 = ptr1.get();
    cout << *ptr3 << endl;


    return 0;
}
