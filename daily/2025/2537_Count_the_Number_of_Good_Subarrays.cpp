#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> count;
        long long curr_good = 0;
        long long ans = 0;
        int right = 0;
        for (int i = 0; i < n; i++){
            while(right < n && curr_good < k){
                curr_good += count[nums[right]];
                count[nums[right]]++;
                right++;
            }
            if (curr_good < k) return ans;
            ans += (n - right + 1);
            count[nums[i]]--;
            curr_good -= count[nums[i]];
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,1,1,1,1};
    int k = 10;
    // vector<int> nums = {3,1,4,3,2,2,4};
    // int k = 2;
    Solution S;
    cout << S.countGood(nums, k) << endl;
    return 0;
}