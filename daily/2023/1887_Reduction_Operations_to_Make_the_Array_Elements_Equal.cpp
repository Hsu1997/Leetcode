#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int count = 0;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[i-1]) count++;
            ans += count;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {5,1,3};
    // vector<int> nums = {1,1,1};
    // vector<int> nums = {1,1,2,2,3};
    Solution S;
    cout << S.reductionOperations(nums) << endl;
    return 0;
}