#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans = {};
//         vector<pair<int,int>> sorted = {};
//         for (int i = 0; i < nums.size(); i++) sorted.push_back(make_pair(nums[i], i));
//         sort(sorted.begin(), sorted.end());
//         int start = 0;
//         int end = nums.size()-1;
//         while(start < end){
//             if (sorted[start].first + sorted[end].first == target) break;
//             else if (sorted[start].first + sorted[end].first > target) end--;
//             else start++;
//         }
//         ans.push_back(sorted[start].second);
//         ans.push_back(sorted[end].second);
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict; 
        for (int i = 0; i < nums.size(); i++){
            if (dict.count(target - nums[i])) return {dict[target - nums[i]], i};
            dict[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution S;
    vector<int> ans = S.twoSum(nums, target);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}