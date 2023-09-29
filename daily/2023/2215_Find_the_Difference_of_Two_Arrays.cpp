#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        unordered_set<int> ans1;
        unordered_set<int> ans2;
        vector<vector<int>> ans(2);
        for (auto i : nums1) if (s2.count(i) == 0) ans1.insert(i);
        for (auto i : nums2) if (s1.count(i) == 0) ans2.insert(i);
        ans[0] = vector<int>(ans1.begin(), ans1.end());
        ans[1] = vector<int>(ans2.begin(), ans2.end());
        return ans;
    }
};

int main(){
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4,6};
    // vector<int> nums1 = {1,2,3,3};
    // vector<int> nums2 = {1,1,2,2};
    Solution S;
    vector<vector<int>> ans = S.findDifference(nums1, nums2);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}