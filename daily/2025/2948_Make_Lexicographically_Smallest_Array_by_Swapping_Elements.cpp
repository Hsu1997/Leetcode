#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> sorted(n);
        for (int i = 0; i < n; i++){
            sorted[i] = {nums[i], i};
        }
        sort(sorted.begin(), sorted.end());
        unordered_map<int,int> index_to_group;
        unordered_map<int,int> group_to_index;
        group_to_index[0] = 0;
        int group = 0;
        for (int i = 1; i < n; i++){
            int curr_num = sorted[i].first;
            int origin_index = sorted[i].second;
            if (sorted[i].first - sorted[i-1].first > limit){
                group++;
                group_to_index[group] = i;
            }
            index_to_group[origin_index] = group;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++){
            ans[i] = sorted[group_to_index[index_to_group[i]]++].first;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,5,3,9,8};
    int limit = 2;
    // vector<int> nums = {1,7,6,18,2,1};
    // int limit = 3;
    // vector<int> nums = {1,7,28,19,10};
    // int limit = 3;
    Solution S;
    vector<int> ans = S.lexicographicallySmallestArray(nums, limit);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}