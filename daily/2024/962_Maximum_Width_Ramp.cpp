#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int ans = 0;
        vector<int> record = {nums[n-1]};
        vector<int> index = {n-1};
        for (int i = n-2; i >= 0; i--){
            auto it = lower_bound(record.begin(), record.end(), nums[i]);
            int idx = it - record.begin();
            if (it == record.end()){
                record.push_back(nums[i]);
                index.push_back(i);
            }
            else ans = max(ans, index[idx] - i);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {6,0,8,2,1,5};
    // vector<int> nums = {9,8,1,0,1,9,4,0,4,1};
    Solution S;
    cout << S.maxWidthRamp(nums) << endl;
    return 0;
}