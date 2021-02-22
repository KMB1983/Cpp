
#include <iostream>
#include <unordered_map>
#include <algorithm>

template<typename K, typename V>
void print_map1(std::unordered_map<K,V> const &m)
{
    for (auto const& pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

class myclass
{
    template<typename K, typename V>
    void operator()(const std::pair<K,V> &p) {
        std::cout << "{" << p.first << ": " << p.second << "}\n";
    }
} ob;

template<typename K, typename V>
void print(const std::pair<K,V> &p) {
    std::cout << "{" << p.first << ": " << p.second << "}\n";
}

template<typename K, typename V>
void print_map2(std::unordered_map<K,V> const &m)
{
    // specify a lambda expression
    std::for_each(m.begin(),
                m.end(),
                [](const std::pair<int, char> &p) {
                    std::cout << "{" << p.first << ": " << p.second << "}\n";
                });

    // or pass object of a class overloading the ()operator
    // std::for_each(m.begin(), m.end(), ob);

    // or specify a function
    // std::for_each(m.begin(), m.end(), print<K,V>);
}

//iterators
template<typename K, typename V>
void print_map_it(std::unordered_map<K,V> const &m)
{
    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        std::cout << "{" << (*it).first << ": " << (*it).second << "}\n";
    }
}

template<typename K, typename V>
std::ostream& operator<<(std::ostream& os,
                        const std::unordered_map<K,V> &m) {
    for (const std::pair<K,V>& p: m) {
        os << "{" << p.first << ": " << p.second << "}\n";
    }
    return os;
}

int main()
{
    std::unordered_map<int, char> m = {
        {1, 'A'},
        {2, 'B'},
        {3, 'C'}
    };
    print_map1(m);
    print_map2(m);
    print_map_it(m);
    // overloaded os stream
    std::cout << m;

    return 0;
}
