#include <iostream>

using namespace std;

template<typename T>
class LinkedList{
private:
    struct Node{
        T data;
        Node* next;
        Node(T data, Node* link=NULL): data(data) {};
    };
    Node* head;
public:

    LinkedList(): head(NULL){}
    Node* getHead() {return  head;}
    void addFirst(const T& data);
    void display() const;
    friend void displayR(LinkedList<T>::Node* head);
};


void displayR(LinkedList<int>::Node* p) {
    if (p) {
        cout << p->data << " -> ";
        displayR(p->next);
    }
}

template<typename T>
void LinkedList<T>::display() const{
    Node* p = head;
    while(p) {
        cout << p->data << " -> ";
        p=p->next;
    }
    cout << endl;
}


template<typename T>
void LinkedList<T>::addFirst(const T& data) {
    Node* p = new Node{data};
    p->next = head;
    head = p;
}

int main() {

    LinkedList<int> l;
    for (int i=0; i!=3; i++) {
        l.addFirst(i);
    }
    //l.display();
    displayR(l.getHead());
    return 0;
}
