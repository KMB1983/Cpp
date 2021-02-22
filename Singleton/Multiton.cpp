#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <string>

using namespace std;

enum class Importance{
    Primary,
    Secondary,
    Terciary,
};

template <typename T, typename Key>
class Multiton{
public:
    static std::shared_ptr<T> get(Key key) {
        const auto it = instances.find(key);
        if (it != instances.end()) {
            return it->second;
        }
        // not found make new instance and add into map
        auto instance = std::make_shared<T>();
        instances[key] = instance;
        return instance;
    }

private:
        static std::map<Key, std::shared_ptr<T>> instances;
protected:
    Multiton() = default;
    virtual ~Multiton() = default;
};

template <typename T, typename Key>
std::map<Key, std::shared_ptr<T>> Multiton<T, Key>::instances;

class Printer{
public:
    Printer() {
        ++Printer::totalInstanceCount;
        std::cout << "Number of instances: " << Printer::totalInstanceCount << std::endl;
    }
private:
    static int totalInstanceCount;
};
int Printer::totalInstanceCount = 0;


int main() {

    using Mt = Multiton<Printer, Importance> ;
    auto main = Mt::get(Importance::Primary);
    auto aux = Mt::get(Importance::Secondary);
    auto aux2 = Mt::get(Importance::Secondary); // wont create new instance


    return 0;
}
