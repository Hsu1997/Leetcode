#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
public:
    vector<int> que;
    int k;
    int front;
    int tail;

    MyCircularQueue(int _k) {
        k = _k+1;
        que = vector<int>(k);
        front = 0;
        tail = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        que[tail] = value;
        tail = (tail + 1) % k;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % k;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return que[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return que[(tail + k - 1) % k];
    }
    
    bool isEmpty() {
        return front == tail;
    }
    
    bool isFull() {
        return (tail + 1) % k == front;
    }
};

int main(){
    MyCircularQueue* myCircularQueue = new MyCircularQueue(3);
    cout << myCircularQueue->enQueue(1) << endl; // return True
    cout << myCircularQueue->enQueue(2) << endl; // return True
    cout << myCircularQueue->enQueue(3) << endl; // return True
    cout << myCircularQueue->enQueue(4) << endl; // return False
    cout << myCircularQueue->Rear() << endl;     // return 3
    cout << myCircularQueue->isFull() << endl;   // return True
    cout << myCircularQueue->deQueue() << endl;  // return True
    cout << myCircularQueue->enQueue(4) << endl; // return True
    cout << myCircularQueue->Rear() << endl;     // return 4
    return 0;
}