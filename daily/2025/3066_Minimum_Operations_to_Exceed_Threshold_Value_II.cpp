#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        priority_queue<long, vector<long>, greater<long>> pq;
        for (int num : nums) pq.push((long)num);
        while(!pq.empty() && pq.top() < k){
            ans++;
            long a = pq.top();
            pq.pop();
            long b = pq.top();
            pq.pop();
            pq.push(a * 2 + b);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,11,10,1,3};
    int k = 10;
    // vector<int> nums = {1,1,2,4,9};
    // int k = 20;
    Solution S;
    cout << S.minOperations(nums, k) << endl;
    return 0;
}