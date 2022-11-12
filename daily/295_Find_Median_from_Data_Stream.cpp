#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
public:
    priority_queue<int> M;
    priority_queue<int, vector<int>, greater<int>> m;

    MedianFinder() {}
    
    void addNum(int num) {
        if (M.empty() || num <= M.top()) M.push(num);
        else m.push(num);

        if (M.size()-1 > m.size()){
            m.push(M.top());
            M.pop();
        }
        if (m.size() > M.size()){
            M.push(m.top());
            m.pop();
        }
    }
    
    double findMedian() {
        return (M.size() == m.size())? (double)(M.top()+m.top())/2 : M.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    MedianFinder *m = new MedianFinder();
    m->addNum(1);
    m->addNum(2);
    cout << m->findMedian() << endl;
    m->addNum(3);
    cout << m->findMedian() << endl;

    // MedianFinder *m = new MedianFinder();
    // m->addNum(1);
    // cout << m->findMedian() << endl;
    // m->addNum(2);
    // cout << m->findMedian() << endl;
    // m->addNum(3);
    // cout << m->findMedian() << endl;
    // m->addNum(4);
    // cout << m->findMedian() << endl;
    // m->addNum(5);
    // cout << m->findMedian() << endl;
    // m->addNum(6);
    // cout << m->findMedian() << endl;
    // m->addNum(7);
    // cout << m->findMedian() << endl;
    // m->addNum(8);
    // cout << m->findMedian() << endl;
    // m->addNum(9);
    // cout << m->findMedian() << endl;
    // m->addNum(10);
    // cout << m->findMedian() << endl;

    return 0;
}