#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int precnt = 0;
        int cnt = 1;
        for (int i = 1; i < n; i++){
            if (nums[i] > nums[i-1]) cnt++;
            else{
                precnt = cnt;
                cnt = 1;
            }
            if ((cnt >= k && precnt >= k ) || cnt >= 2 * k) return true;
        }
        return false;
    }
};

int main(){
    vector<int> nums = {2,5,7,8,9,2,3,4,3,1};
    int k = 3;
    // vector<int> nums = {1,2,3,4,4,4,4,5,6,7};
    // int k = 5;
    // vector<int> nums = {-15,19};
    // int k = 1;
    Solution S;
    cout << S.hasIncreasingSubarrays(nums, k) << endl;
    return 0;
}