#include <iostream>

using namespace std;

class EmptyDoubleLinkedListException{
};

template<class T>
class DoubleLinkedList{
private:
        struct Node{
            T data;
            Node *prev, *next;

            Node(T val, Node *p=0, Node *n=0): data(val), prev(p), next(n) {};
        };

        Node *head;
public:

    DoubleLinkedList(): head(0){};

    bool Empty() const { return head == NULL;};

    void addFirst(const T &val);
    void addLast(const T &val);

    T delFirst();
    void del(const T &val);
    void display();

};

template<class T> void DoubleLinkedList<T>::del(const T &val) {
    if (head == NULL) { throw EmptyDoubleLinkedListException();}
    if (head->data == val) {
        delFirst();
        return;
    }
    Node *n = head;
    while (n != NULL && n->data != val) {
        n = n->next;
    }
    if (n==NULL) {return;} // not found
    Node *m = n->next;
    Node *p = n->prev;
    n->next = NULL;
    n->prev = NULL;
    delete n;

    p->next = m;
    m->prev = p;

}

template<class T> T DoubleLinkedList<T>::delFirst(){
    if (head==NULL) { throw EmptyDoubleLinkedListException();}
    T val = head->data;
    Node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = temp;
    }
    delete temp;
    return val;
}

template<typename T> void DoubleLinkedList<T>::addLast(const T &val) {
    if (head==NULL) addFirst(val);

    Node *n = new Node(val);
    Node *temp = head;
    while (temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

template<class T> void DoubleLinkedList<T>::addFirst(const T &val) {
    Node *n = new Node(val);
    n->next = head;
    if (head!=NULL){
        head->prev = n;
    }
    head = n;
}

template<typename T> void DoubleLinkedList<T>::display() {
    Node *temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ->";
        temp = temp->next;
    }
    std::cout << "]\n";
}

int main() {

    DoubleLinkedList<int> dl;
    if (dl.Empty()) {
     cout << "List is empty\n";
    }

    dl.addFirst(10);
    dl.addFirst(20);
    dl.addLast(30);
    dl.addLast(40);
    dl.addLast(50);
    dl.display();
    dl.delFirst();
    dl.display();
    dl.del(40);
    dl.display();


    return 0;
};
