#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Drawable{

public:
    virtual void draw() const = 0; // pure virtual function

    //must be virtual otherwise we have memory leak
    virtual ~Drawable() {
        cout << "Drawable destroyed\n";
    }
};


class Circle: public Drawable{
public:
    void draw() const override {
        cout << "Drawing Circle\n";
    }
    ~Circle() {
        cout << "Circle destroyed\n";
    }
};

class Triangle : public Drawable{
public:
    void draw() const override {
        cout << "Drawing Traingle\n";
    }


};


void drawShape(const Drawable& d) {
    d.draw();
}

int main() {

    // Vectors has pointers of different types, call right methods

    std::vector< std::unique_ptr<Drawable> > shapes;
    shapes.push_back(make_unique<Circle>());
    shapes.push_back(make_unique<Triangle>());

    for (auto &shape: shapes) {
        shape->draw();
    }

    // will call the right method - triangle even if we pass drawable
    Triangle triangle;
    drawShape(triangle);

    Drawable* c = new Circle;
    c->draw();
    delete c;

    return 0;
}
