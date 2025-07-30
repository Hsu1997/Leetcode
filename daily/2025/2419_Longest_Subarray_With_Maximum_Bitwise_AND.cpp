#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int curr = 0;
        int M = 0;
        for (int i : nums){
            if (i < M) curr = 0;
            else{
                if (i == M) curr++;
                else{
                    M = i;
                    curr = 1;
                    ans = 1;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,3,2,2};
    // vector<int> nums = {1,2,3,4};
    Solution S;
    cout << S.longestSubarray(nums) << endl;
    return 0;
}