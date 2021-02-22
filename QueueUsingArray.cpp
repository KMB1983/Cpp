#include <iostream>
#include <string>

using namespace std;

class QueueException{
private:
        string _msg;
public:
        QueueException(const string& msg): _msg(msg){}
        string getMessage() const {return _msg;};
};


template<typename T>
class Queue{
private:
    T *_queue;
    int _capacity;
    int _front, _rear;
public:
    Queue(int n): _capacity(n), _queue(new T[n+1]), _front(0), _rear(0){}
    ~Queue() { delete []_queue;}

    const bool empty() const { return _front == _rear;}
    const bool full() const { return (_rear + 1) % _capacity == _front; } // adding one more will reach the front elem;

    void insert(const T& elem){
        if (full())
            throw QueueException("queue is full!");
        _queue[++_rear] = elem;

    }

    T extract() {
        if (empty())
            throw QueueException("queue is empty!");
        _front = (_front + 1) % _capacity;
        return _queue[_front];
    }

};


int main() {

    Queue<int> q(15);

    for (size_t i =0; i!= 10; i++){
        q.insert(2*i);
    }

    while (!q.empty()) {
        cout << q.extract() << " ";
    }

    cout << "\n\n";

    try {
        q.extract();
    } catch (QueueException &e) {
        cout << e.getMessage()<<endl;
    }


    return 0;
}

