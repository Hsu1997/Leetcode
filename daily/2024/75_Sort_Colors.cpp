#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int one = 0;
        for (int i : nums){
            if (i == 0) zero++;
            if (i == 1) one++;
        }
        for (int i = 0; i < n; i++){
            if (zero-- > 0) nums[i] = 0;
            else if (one-- > 0) nums[i] = 1;
            else nums[i] = 2;
        }
    }
};

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    // vector<int> nums = {2,0,1};
    Solution S;
    S.sortColors(nums);
    for (auto i : nums) cout << i << " ";
    cout << endl;
    return 0;
}