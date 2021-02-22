#include <iostream>
#include <string>

using namespace std;

class EmptyStackException{
private:
        string _msg;
public:
    EmptyStackException(string msg): _msg(msg){};
    string getMessage() const { return _msg;}

};

template<typename T>
class Stack{
private:
    struct Node {
        T data;
        Node* next;

        Node(T data): data(data), next(NULL){}
        Node(T data, Node *n): data(data), next(n){}
    };

    Node *top;

public:
    Stack(): top(NULL){}
    const bool empty() const {return top == NULL;};

    void push(const T &elem);
    T pop();

};

template<typename T> T  Stack<T>::pop(){
    if (empty()) { throw EmptyStackException("Underflow");}

    Node *temp = top;
    top = top->next;
    T val = temp->data;
    delete temp;
    return val;
}

template<typename T> void PrintStack(Stack<T>& stk) {
    while (!stk.empty()) {
        cout << stk.pop() << " <- ";
    }

}

template<typename T> void Stack<T>::push(const T &elem) {
    Node *n = new Node(elem);
    if (empty()) {
        top = n;
        return;
    }
    n->next = top;
    top = n;
}



int main() {

    Stack<int> stk;

    try {
        for (size_t i = 1; i<=5; i++) {
            stk.push(i);
        }
        while (!stk.empty()) {
            cout << stk.pop() << " <- ";
        }


    } catch (EmptyStackException &e) {
        cout << e.getMessage() << endl;;
    }
    return 0;
}
