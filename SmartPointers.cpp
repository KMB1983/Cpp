#include <iostream>
#include <memory>

class List{
public:
    struct Node{
        int data;
        std::unique_ptr<Node> next;

        Node(int data) : data{data}, next{nullptr} {}
    };

    List() : head{nullptr} {}

    ~List() {
        while(head) {
            std::cout << head->data << ":Destroyed - ";
            head = std::move(head->next);
        }
    }

    void push(int data) {
        auto temp = std::make_unique<Node>(data);
        if (head) {
            temp->next = std::move(head);
        }
        head = std::move(temp);
    }
    void Print() {
        Node* temp = head.get();
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = std::move(temp->next.get());
        }
        std::cout << std::endl;
    }

    friend void PrintList2(const List& l);

private:
    std::unique_ptr<Node> head;
};

std::unique_ptr<int> createPtr(int data) {
    data++;
    std::unique_ptr<int> p = std::make_unique<int>(data);
    return p;
}

void PrintList2(const List& l) {
    List::Node* temp = l.head.get();
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next.get();
    }
    std::cout << std::endl;
}

int main() {

    // how to construct sharePointer
    std::shared_ptr<int> shrPtr1{new int{36}};
    auto shrPtr2{std::make_shared<int>(20)};


    std::unique_ptr<int> upi{createPtr(1)};
    std::cout << *upi << std::endl;

    List l;
    for (size_t i=0; i != 10; i++) {
        l.push(i);
    }

    PrintList2(l);
    PrintList2(l);

    l.Print();



    return 0;
};
