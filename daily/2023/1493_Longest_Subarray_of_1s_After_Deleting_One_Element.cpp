#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int temp = 0;
        int zero = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++){
            // cout << j;
            (nums[j])? temp++ : zero++;
            if (zero > 1){
                while(nums[i++]) temp--;
                zero--;
            }
            ans = max(ans, temp);
            // cout << "-" << i << ", ans = " << ans << endl; 
        }
        if (ans == nums.size()) return ans-1;
        return ans;
    }
};

int main(){
    // vector<int> nums = {1,1,0,1};
    vector<int> nums = {0,1,1,1,0,1,1,0,1};
    Solution S;
    cout << S.longestSubarray(nums) << endl;
    return 0;
}