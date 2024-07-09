#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long total_cost = 0;
        long long cost_down = 0;
        long long cost_up = 0;
        map<int,int> node;
        for (int i = 0; i < n; i++){
            node[nums[i]] += cost[i];
            cost_up += cost[i];
            total_cost += (long long)nums[i] * cost[i];
        }
        vector<pair<int,int>> list;
        for (auto i : node) list.push_back({i.first, i.second});
        // for (auto i : list) cout << i.first << " " << i.second << endl;
        n = list.size();
        long long ans = LLONG_MAX;
        int pre_bar = 0;
        
        for (int i = 0; i < n; i++){
            total_cost = total_cost + (list[i].first - pre_bar) * (cost_down - cost_up);
            pre_bar = list[i].first;
            ans = min(ans, total_cost);
            // cout << "cost = " << total_cost << ", down = " << cost_down << ", up = " << cost_up << endl;
            cost_down += list[i].second;
            cost_up -= list[i].second;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,5,2};
    vector<int> cost = {2,3,1,14};
    // vector<int> nums = {2,2,2,2,2};
    // vector<int> cost = {4,2,8,1,3};
    Solution S;
    cout << S.minCost(nums, cost) << endl;
    return 0;
}