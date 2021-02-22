#include <iostream>

class ListEmptyException{

};

template<class T>
class LinkedList{
private:
    struct Node{
        T data;
        Node* next;

        Node(T val, Node* link=NULL): data(val), next(link) {}
    };

    Node* head;

public:
    LinkedList<T>(): head(NULL) {};

    bool isEmpty() const { return head == NULL; }

    void addFirst(const T& val);
    void addLast(const T& val);

    void del(const T& val);
    T delFirst();

    void display();

    void reverseList();
};

template<typename T> void LinkedList<T>::reverseList() {
    if (head == NULL || head->next == NULL) { return;}
    Node *p, *q = head, *r = head->next;
    head->next = NULL;
    while (r!=NULL) {
        p = q;
        q = r;
        if (r!=NULL) {
            r= r->next;
            q->next = p;
        }
    }
}

template<class T> void LinkedList<T>::del(const T& val){
    if (head == NULL) throw ListEmptyException();
    if (head->data == val) {
            delFirst();
    } else {
        Node *prev, *current = head; // init current with head and prev uninitilized
        while (current!=NULL && current->data != val) {
            prev = current;
            current = current->next;
        }
        if (current==NULL) {
            return;
        }
        prev->next = current->next;
        current->next = NULL; //isolation step
        delete current;
    }


}

template<class T> T LinkedList<T>::delFirst() {
    if (head == NULL) {
        throw ListEmptyException();
    }
    Node* temp = head;
    T val = head->data;
    head = head->next;
    temp->next = NULL;
    delete temp;
    return val;

}

template<class T> void LinkedList<T>::addFirst(const T& val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

template<typename T> void LinkedList<T>::addLast(const T& val) {
    if (isEmpty()) { addFirst(val);}
    Node* p = head;
    while (p->next != NULL) {
        p=p->next;
    }
    Node* n = new Node(val);
    p->next = n;
}

template<class T> void LinkedList<T>::display() {
    Node* temp = head;
    std::cout << "\n[";
    while (temp!=NULL) {
        std::cout << temp->data << " -> ";
        temp= temp->next;
    }
    std::cout << "]\n";
}

int main() {

    LinkedList<int> l;

    try {
        int val = l.delFirst();
    }
    catch (ListEmptyException& e) {
        std::cout<< "List is empty.\n";
    }

    l.addFirst(10);
    l.addFirst(20);
    l.addFirst(30);
    l.addLast(40);
    l.addLast(50);
    l.display();

    try {
        int val = l.delFirst();
    }
    catch (ListEmptyException& e) {
        std::cout<< "List is empty.\n";
    }
    l.display();

    l.del(40);
    l.del(45);
    l.display();
    l.reverseList();
    l.display();

    return 0;
}
