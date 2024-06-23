#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> que = {nums[0]};
        int left = 0;
        int right = 1;
        int ans = 1;
        while(left < n || right < n){
            // for (auto i : que) cout << i << " ";
            // cout << endl;
            if (right == n || abs(que.back() - *que.begin()) > limit){
                que.erase(lower_bound(que.begin(), que.end(), nums[left]));
                left++;
            }
            else{
                que.insert(lower_bound(que.begin(), que.end(), nums[right]), nums[right]);
                right++;
                if (abs(que.back() - *que.begin()) <= limit) ans = max(ans, right - left);
                // cout << "ans = " << ans << endl;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {8,2,4,7};
    int limit = 4;
    // vector<int> nums = {10,1,2,4,7,2};
    // int limit = 5;
    // vector<int> nums = {4,2,2,2,4,4,2,2};
    // int limit = 0;
    Solution S;
    cout << S.longestSubarray(nums, limit) << endl;
    return 0;
}