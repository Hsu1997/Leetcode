#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n = nums.size();
        int start = 0;
        int ans = 0;
        for (int end = 0; end < n; end++){
            freq[nums[end]]++;
            while(freq[nums[end]] > k){
                freq[nums[start++]]--;
            }
            ans = max(ans, end - start + 1);
        }
        ans = max(ans, n - start);
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,1,2,3,1,2};
    int k = 2;
    // vector<int> nums = {1,2,1,2,1,2,1,2};
    // int k = 1;
    // vector<int> nums = {5,5,5,5,5,5,5};
    // int k = 4;
    Solution S;
    cout << S.maxSubarrayLength(nums, k) << endl;
    return 0;
}