#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[0] + a[1] > b[0] + b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, function<bool(const vector<int>&, const vector<int>&)>> pq(cmp);
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> ans;
        for (int j = 0; j < n2; j++) pq.push({nums1[0], nums2[j], 0});
        while(ans.size() < k){
            vector<int> cur = pq.top();
            pq.pop();
            int index = cur[2];
            ans.push_back({cur[0], cur[1]});
            if (index+1 < n1) pq.push({nums1[index+1], cur[1], index+1});
        }
        return ans;
    }
};

int main(){
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};
    int k = 3;
    // vector<int> nums1 = {1,1,2};
    // vector<int> nums2 = {1,2,3};
    // int k = 2;
    Solution S;
    vector<vector<int>> ans = S.kSmallestPairs(nums1, nums2, k);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}