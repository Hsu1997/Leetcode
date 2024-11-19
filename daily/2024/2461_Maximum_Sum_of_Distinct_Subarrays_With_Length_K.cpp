#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long acc = 0;
        int n = nums.size();
        unordered_map<int,int> count;
        int duplicated = 0;
        for (int i = 0; i < k; i++){
            if (count[nums[i]] == 1) duplicated++;
            count[nums[i]]++;
            acc += nums[i];
        }
        if (duplicated == 0) ans = acc;
        for (int idx = k; idx < n; idx++){
            int add = nums[idx];
            int del = nums[idx-k];
            acc += add - del;
            if (count[add] == 1) duplicated++;
            count[add]++;
            if (count[del] == 2) duplicated--;
            count[del]--;
            if (duplicated == 0) ans = max(ans, acc);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,5,4,2,9,9,9};
    int k = 3;
    // vector<int> nums = {4,4,4};
    // int k = 3;
    Solution S;
    cout << S.maximumSubarraySum(nums, k) << endl;
    return 0;
}