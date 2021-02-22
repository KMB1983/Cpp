#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

struct GraphicObject{
    virtual void draw() = 0;
};

struct Circle: GraphicObject{
    void draw() override {
        cout << "Drawing Circle!\n";
    }
};

struct Group: GraphicObject{
    string name;
    //std::vector<GraphicObject*> objects;
    std::vector<std::unique_ptr<GraphicObject>> objects;

    Group(const std::string & name): name(name) {};
    void draw() override {
        std::cout << "Group: " << name << " contains->" << std::endl;
        for (auto&& obj: objects) {
            obj->draw();
        }
    }
};

int main() {
    Group root{"root"};
    Circle c1, c2;
    root.objects.push_back(std::make_unique<Circle>(c1));
    root.objects.push_back(std::make_unique<Circle>(c2));

    /*
    root.objects.push_back(&c1);
    root.objects.push_back(&c2);

    Group subgroup{"sub"};
    Circle c3;
    subgroup.objects.push_back(&c3);
    root.objects.push_back(&subgroup);
    */
    root.draw();

}


