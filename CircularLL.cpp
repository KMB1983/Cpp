#include <iostream>

using namespace std;

class EmptyListException{
};

template<typename T>
class CircularLinkedList{
private:
    struct Node{
        T data;
        Node *next;

        Node(T val, Node *link=0): data(val), next(link){}
    };

    Node *head;
    Node *tail;
public:
    CircularLinkedList(){
        head = NULL;
        tail = NULL;
    }
    bool empty() const { return head == NULL && tail == NULL;}

    void addFirst(const T& elem);
    void addLast(const T& elem);

    T delFirst();
    void del(const T &elem);

    void display();
};

template<typename T> void CircularLinkedList<T>::addFirst(const T &elem) {
    Node *n = new Node(elem);
    if (this->empty()) {
        tail = n;
        tail->next = n;
    } else{
        n->next = head;
        tail->next = n;
    }

    head = n;

}

template<typename T> void CircularLinkedList<T>::addLast(const T &elem) {
    if (this->empty()) { addFirst(elem);}
    Node *n = new Node(elem);
    Node *m = head;
    while (m->next !=head) {
        m = m->next;
    }
    m->next = n;
    n->next = head;
    tail = n;

}

template<typename T> void CircularLinkedList<T>::display() {
    Node * temp = head;
    std::cout << "[ ";
    while (temp != tail) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << temp->data <<" ]\n";
}

template<typename T> T CircularLinkedList<T>::delFirst(){
    if (empty()) { throw EmptyListException();}
    T val = head->data;
    if (head == tail) {
        head = tail = NULL;
    } else {
        Node *temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;
        delete temp;
    }
    return val;
}

int main() {

    CircularLinkedList<int> cl;
    //cout << cl.empty();
    cl.addFirst(30);
    cl.addFirst(20);
    cl.addFirst(10);
    cl.addFirst(1);
    cl.display();
    cl.addLast(40);
    cl.display();
    cl.delFirst();
    cl.display();





    return 0;
}
