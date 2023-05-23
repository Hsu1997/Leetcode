#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    int s;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        s = k;
        for (auto i : nums){
            pq.push(i);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > s) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(){
    int k = 3;
    vector<int> nums = {4,5,8,2};
    // int k = 1;
    // vector<int> nums = {0};
    KthLargest* kthLargest = new KthLargest(k, nums);
    cout << kthLargest->add(3) << endl;   // return 4
    cout << kthLargest->add(5) << endl;   // return 5
    cout << kthLargest->add(10) << endl;  // return 5
    cout << kthLargest->add(9) << endl;   // return 8
    cout << kthLargest->add(4) << endl;   // return 8
    return 0;
}