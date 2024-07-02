#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> m;
        for (auto i : nums1) m[i]++;
        for (auto i : nums2){
            if (m[i]) ans.push_back(i), m[i]--;
        }
        return ans;
    }
};

int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    // vector<int> nums1 = {4,9,5};
    // vector<int> nums2 = {9,4,9,8,4};
    Solution S;
    vector<int> ans = S.intersect(nums1, nums2);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}