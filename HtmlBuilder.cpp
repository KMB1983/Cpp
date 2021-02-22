#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class HtmlBuilder;

class HtmlElement{
public:
    string name, text;
    vector<HtmlElement> elements{};
    const size_t indent_size = 2;

    HtmlElement() = default;
    HtmlElement(const string& name, const string & text) : name(name), text(text){}

    string str(int indent = 0) const{
        ostringstream oss;
        string i(indent_size*indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if (text.size() > 0)
          oss << string(indent_size*(indent + 1), ' ') << text << endl;

        for (const auto& e : elements)
          oss << e.str(indent + 1);

        oss << i << "</" << name << ">" << endl;
        return oss.str();
      }
    static std::unique_ptr<HtmlBuilder> build(string root_name) {
        return std::make_unique<HtmlBuilder>(root_name);
    }
};

class HtmlBuilder{
public:
    HtmlElement root;

    HtmlBuilder(string root_name) {
        root.name = root_name;
        }
    string str() {return root.str();}
    HtmlElement operator()() const { return root;}

    HtmlBuilder& addChild(string child_name, string child_text) {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return *this;
    }
    HtmlBuilder* addChild2(const string& child_name, const string & child_text) {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return this;
    }

};

int main() {

    HtmlBuilder builder("li");
    builder.addChild("lu", "Hello").addChild("lu", "Babu Kajo Majo");
    std::cout << builder.str();

    auto builder2 = HtmlElement::build("li");
    builder2->addChild2("lu", "Morning");

    cout<< builder2->str();


    return 0;
}
