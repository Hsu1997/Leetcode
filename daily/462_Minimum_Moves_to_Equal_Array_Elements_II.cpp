#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int medium = (n%2 == 1)? nums[n/2] : (nums[n/2 - 1] + nums[n/2])/2;
        int total = 0;
        for (auto i : nums) total += abs(medium - i);
        return total;
    }
};

int main(){
    vector<int> nums = {1,10,2,9};
    Solution S;
    cout << S.minMoves2(nums) << endl;
    return 0;
}