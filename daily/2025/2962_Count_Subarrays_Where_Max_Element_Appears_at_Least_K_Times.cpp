#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int M = *max_element(nums.begin(), nums.end());
        vector<int> index;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == M) index.push_back(i);
            int freq = index.size();
            if (freq >= k){
                ans += index[freq - k] + 1;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,2,3,3};
    int k = 2;
    // vector<int> nums = {1,4,2,1};
    // int k = 3;
    Solution S;
    cout << S.countSubarrays(nums, k) << endl;
    return 0;
}