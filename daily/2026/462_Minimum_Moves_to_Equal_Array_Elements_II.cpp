#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int med = nums[nums.size() / 2];
        int ans = 0;
        for (auto i : nums) ans += abs(med - i);
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    // vector<int> nums = {1,10,2,9};
    Solution S;
    cout << S.minMoves2(nums) << endl;
    return 0;
}