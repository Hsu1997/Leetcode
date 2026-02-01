#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int s1 = INT_MAX;
        int s2 = INT_MAX;
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] < s2){
                s2 = max(nums[i], s1);
                s1 = min(nums[i], s1);
            }
        }
        ans += s1 + s2;
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,12};
    // vector<int> nums = {5,4,3};
    // vector<int> nums = {10,3,1,1};
    Solution S;
    cout << S.minimumCost(nums) << endl;
    return 0;
}