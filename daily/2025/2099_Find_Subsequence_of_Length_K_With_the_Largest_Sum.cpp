#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        vector<int> ans;
        unordered_map<int,int> count;
        for (int i = 0; i < k; i++) count[arr[n - 1 - i]]++;
        for (int i : nums){
            if (count[i]){
                ans.push_back(i);
                count[i]--;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,1,3,3};
    int k = 2;
    // vector<int> nums = {-1,-2,3,4};
    // int k = 3;
    // vector<int> nums = {3,4,3,3};
    // int k = 2;
    Solution S;
    vector<int> ans = S.maxSubsequence(nums, k);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}