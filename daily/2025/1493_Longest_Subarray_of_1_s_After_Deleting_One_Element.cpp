#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        nums.push_back(0);
        int prev = -1;
        int cnt = 0;
        int ans = 0;
        for (int i : nums){
            if (i == 1) cnt++;
            else{
                ans = max(ans, prev + cnt);
                prev = cnt;
                cnt = 0;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,1,0,1};
    // vector<int> nums = {0,1,1,1,0,1,1,0,1};
    // vector<int> nums = {1,1,1};
    Solution S;
    cout << S.longestSubarray(nums) << endl;
    return 0;
}