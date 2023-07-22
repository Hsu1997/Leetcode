#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> LIS;
        vector<int> length(n);
        vector<int> count(n);
        for (int i = 0; i < n; i++){
            int index = lower_bound(LIS.begin(), LIS.end(), nums[i]) - LIS.begin();
            if (index == LIS.size()) LIS.push_back(i);
            LIS[index] = nums[i];
            length[i] = index+1;
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j] && length[j]+1 == length[i]) count[i] += count[j];
            }
            if (count[i] == 0) count[i] = 1;
        }
        for (auto i : LIS) cout << i << " ";
        cout << endl;
        for (auto i : length) cout << i << " ";
        cout << endl;
        for (auto i : count) cout << i << " ";
        cout << endl;
        for (int i = 0; i < n; i++) if (length[i] == LIS.size()) ans += count[i];
        return ans;
    }
};

int main(){
    // vector<int> nums = {1,3,5,4,7};
    // vector<int> nums = {2,2,2,2,2};
    vector<int> nums = {1,2,4,3,5,4,7,2};
    Solution S;
    cout << S.findNumberOfLIS(nums) << endl;
    return 0;
}