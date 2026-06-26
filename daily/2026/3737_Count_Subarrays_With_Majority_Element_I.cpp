#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> acc(n, 0);
        acc[0] = (nums[0] == target);
        for (int i = 1; i < n; i++){
            acc[i] = acc[i-1] + (nums[i] == target);
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                int c = acc[j] - ((i > 0)? acc[i-1] : 0);
                if (c * 2 > j - i + 1) ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,2,3};
    int target = 2;
    // vector<int> nums = {1,1,1,1};
    // int target = 1;
    // vector<int> nums = {1,2,3};
    // int target = 4;
    Solution S;
    cout << S.countMajoritySubarrays(nums, target) << endl;
    return 0;
}
