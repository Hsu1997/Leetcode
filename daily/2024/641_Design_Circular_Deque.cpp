#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque {
public:
    vector<int> container;
    int start, end, n;

    MyCircularDeque(int k) {
        n = k + 1;
        container.resize(n);
        start = 0;
        end = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        if (isEmpty()) return insertLast(value);
        start = (start + n - 1) % n;
        container[start] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        container[end] = value;
        end = (end + 1) % n;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        start = (start + 1) % n;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        end = (end + n - 1) % n;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return container[start];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return container[(end + n - 1) % n];
    }
    
    bool isEmpty() {
        return start == end;
    }
    
    bool isFull() {
        return (end + 1) % n == start;
    }
};

int main(){
    MyCircularDeque* myCircularDeque = new MyCircularDeque(3);
    cout << myCircularDeque->insertLast(1) << " ";
    cout << myCircularDeque->insertLast(2) << " ";
    cout << myCircularDeque->insertFront(3) << " ";
    cout << myCircularDeque->insertFront(4) << " ";
    cout << myCircularDeque->getRear() << " ";
    cout << myCircularDeque->isFull() << " ";
    cout << myCircularDeque->deleteLast() << " ";
    cout << myCircularDeque->insertFront(4) << " ";
    cout << myCircularDeque->getFront() << endl;
    return 0;
}