#include <iostream>
#include <vector>
#include <string>


using namespace  std;

class AlphaBuilder;

class Alpha{
private:
    string _name;
    std::vector<string> inputs;

public:
    Alpha(){
        std::cout << "Alpha created!" << std::endl;
    }
    ~Alpha() {
        std::cout << "Alpha destroyed!" << std::endl;
    }

    static AlphaBuilder create() { return AlphaBuilder();};

    friend class AlphaBuilder;

};

class AlphaBuilderBase{
protected:
    Alpha& alpha;
    AlphaBuilderBase(Alpha& alpha): alpha(alpha){};
    operator Alpha() const { return alpha;}

};

class AlphaBuilder: public AlphaBuilderBase{
private:
    Alpha alpha;
    AlphaBuilder(): AlphaBuilderBase(alpha){}
};


int main() {


    return 0;
}
