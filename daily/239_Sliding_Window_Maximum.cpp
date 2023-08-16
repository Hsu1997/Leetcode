#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> m;
        priority_queue<int> pq;
        for (int i = 0; i < k; i++){
            pq.push(nums[i]);
            m[nums[i]]++;
        }
        ans.push_back(pq.top());
        for (int i = k; i < n; i++){
            m[nums[i]]++;
            m[nums[i-k]]--;
            pq.push(nums[i]);
            while(m[pq.top()] == 0) pq.pop();
            ans.push_back(pq.top());
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution S;
    vector<int> ans = S.maxSlidingWindow(nums, k);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}