#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Color {red, green, blue};
enum class Size {small, medium, large};

struct Product{
    string name;
    Color color;
    Size size;
};

template <typename T>
struct Specification{
    virtual ~Specification() = default;
    virtual bool IsSatisfied(T* item) const = 0; // pure virtual, will be overide
};

template <typename T>
struct Filter{
    virtual vector<T*> filter(vector<T*> items,
                              Specification<T>& spec) = 0;

};

struct BetterFilter : Filter<Product>{
    vector<Product*> filter(vector<Product*> items, Specification<Product>& spec) override {
        vector<Product*> res{};
        for (auto &item: items) {
            if (spec.IsSatisfied(item)) {
                res.push_back(item);
            }
        }
        return res;
    }
};

struct ColorSpec: Specification<Product> {
    Color color;
    ColorSpec(Color c): color(c){};
    bool IsSatisfied(Product* item) const override { return item->color == color;}
};

int main() {
    Product apple{"Apple", Color::green, Size::small};
    Product car{"Car", Color::blue, Size::medium};
    Product tree{"Tree", Color::green, Size::large};

    const vector<Product*> products{&apple, &car, &tree};
    //std::cout << products.at(0)->name;
    BetterFilter bf;
    ColorSpec green(Color::green);
    auto res = bf.filter(products, green);
    for (auto &val: res) {
        std::cout << val->name << std::endl;
    }

    return 0;
}
