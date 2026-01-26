#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int mod = 1e9 + 7;
        unordered_map<int,int> left;
        unordered_map<int,int> right;
        for (int i : nums) right[i]++;
        for (int i = 0; i < n; i++){
            int curr = nums[i];
            right[curr]--;
            int l = left[curr * 2];
            int r = right[curr * 2];
            ans = (ans + 1LL * l * r) % mod;
            left[curr]++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {6,3,6};
    // vector<int> nums = {0,1,0,0};
    // vector<int> nums = {8,4,2,8,4};
    Solution S;
    cout << S.specialTriplets(nums) << endl;
    return 0;
}