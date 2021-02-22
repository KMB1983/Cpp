#include <iostream>
#include <string>

using namespace std;

class StackException{
private:
    string _msg;
public:
    StackException(string msg): _msg(msg){};

    string getMessage() { return _msg;}
};

template <typename T>
class Stack {
private:
    T *_stack;
    int _top, _size;
public:
    Stack(int n) {
        _stack = new T[n];
        _size = n;
        _top=-1;
    }
    ~Stack(){ delete []_stack;}

    const bool empty() const { return _top == -1;}
    void push(const T& elem);
    T top();

};

template<typename T> T Stack<T>::top() {
    if (_top == -1) {
        throw StackException("Underflow");
    }
    return _stack[_top--];
}

template<typename T> void Stack<T>::push(const T& elem){
    if (_top == _size - 1) {
        throw StackException("Overflow");
    }
    _top++;
    _stack[_top] = elem;
}

template<typename T>
void PrintStack(Stack<T>& stk) {
    while (!stk.empty()) {
        cout << stk.top() << " ";
    }
}

int main() {

    Stack<int> stk(3);
    stk.push(1);
    stk.push(2);
    stk.push(3);
    try {
        stk.push(4);
    }
    catch (StackException &e) {
        cout << e.getMessage() << endl;
    }

    PrintStack<int>(stk);
    return 0;
}
