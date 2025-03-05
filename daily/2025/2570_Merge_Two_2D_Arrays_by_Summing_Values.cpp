#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> m;
        for (vector<int>& num : nums1) m[num[0]] += num[1];
        for (vector<int>& num : nums2) m[num[0]] += num[1];
        vector<vector<int>> ans;
        for (auto& [id, val] : m) ans.push_back({id, val});
        return ans;
    }
};

int main(){
    vector<vector<int>> nums1 = {{1,2},{2,3},{4,5}};
    vector<vector<int>> nums2 = {{1,4},{3,2},{4,1}};
    // vector<vector<int>> nums1 = {{2,4},{3,6},{5,5}};
    // vector<vector<int>> nums2 = {{1,3},{4,3}};
    Solution S;
    vector<vector<int>> ans = S.mergeArrays(nums1, nums2);
    for (auto i : ans){
        for (int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}