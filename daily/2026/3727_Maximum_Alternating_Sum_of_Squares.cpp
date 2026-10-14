#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a) > abs(b);
        });
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < (n + 1) / 2; i++){
            ans += (1LL * nums[i] * nums[i]);
        }
        for (int i = (n + 1) / 2; i < n; i++){
            ans -= (1LL * nums[i] * nums[i]);
        }
        return ans;
    }
};

int main(){
    // vector<int> nums = {1,2,3};
    vector<int> nums = {1,-1,2,-2,3,-3};
    Solution S;
    cout << S.maxAlternatingSum(nums) << endl;
    return 0;
}