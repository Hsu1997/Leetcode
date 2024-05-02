#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int rev(int i){
        int a = 0;
        while(i){
            a *= 10;
            a += i % 10;
            i /= 10;
        }
        return a;
    }

    int countNicePairs(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        unordered_map<int,int> m;
        int ans = 0;
        int mod = 1e9+7;
        for (int i = nums.size()-1; i >= 0; i--){
            ans = (ans + m[nums[i] - rev(nums[i])]++) % mod;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {42,11,1,97};
    // vector<int> nums = {13,10,35,24,76};
    Solution S;
    cout << S.countNicePairs(nums) << endl;
    return 0;
}