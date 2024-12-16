#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto cmp = [&](int a, int b){
            if (nums[a] == nums[b]) return a > b;
            else return nums[a] > nums[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int n = nums.size();
        for (int i = 0; i < n; i++) pq.push(i);
        while(k--){
            int i = pq.top();
            pq.pop();
            nums[i] *= multiplier;
            pq.push(i);
        }
        return nums;
    }
};

int main(){
    vector<int> nums = {2,1,3,5,6};
    int k = 5;
    int multiplier = 2;
    // vector<int> nums = {1,2};
    // int k = 3;
    // int multiplier = 4;
    Solution S;
    vector<int> ans = S.getFinalState(nums, k, multiplier);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}