#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;

    KthLargest(int k, vector<int>& nums) {
        n = k;
        for (int i : nums){
            pq.push(i);
            if (pq.size() > n) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > n) pq.pop();
        return pq.top();
    }
};

int main(){
    int k = 3;
    vector<int> nums = {4,5,8,2};
    KthLargest *kthLargest = new KthLargest(k, nums);
    cout << kthLargest->add(3) << endl;   // return 4
    cout << kthLargest->add(5) << endl;   // return 5
    cout << kthLargest->add(10) << endl;  // return 5
    cout << kthLargest->add(9) << endl;   // return 8
    cout << kthLargest->add(4) << endl;   // return 8
}