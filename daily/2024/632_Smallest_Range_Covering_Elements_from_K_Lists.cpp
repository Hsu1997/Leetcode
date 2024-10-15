#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        auto compare = [](pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b){
            return a.first >= b.first;
        };
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, decltype(compare)> pq(compare);
        int pq_max = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            pq.push({nums[i][0], {i, 0}});
            pq_max = max(pq_max, nums[i][0]);
        }
        int ans_start = INT_MIN;
        int ans_len = INT_MAX;
        while(!pq.empty()){
            auto [num, info] = pq.top();
            auto [l, idx] = info;
            pq.pop();
            if (pq_max - num < ans_len){
                ans_len = pq_max - num;
                ans_start = num;
            }
            if (idx == nums[l].size() - 1) return {ans_start, ans_start + ans_len};
            pq.push({nums[l][idx+1], {l, idx+1}});
            pq_max = max(pq_max, nums[l][idx+1]);
        }
        return {-1,-1};
    }
};

int main(){
    vector<vector<int>> nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    // vector<vector<int>> nums = {{1,2,3},{1,2,3},{1,2,3}};
    Solution S;
    vector<int> ans = S.smallestRange(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}