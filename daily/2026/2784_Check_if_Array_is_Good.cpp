#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> cnt(n + 1);
        for (int num : nums){
            if (num > n) return false;
            cnt[num]++;
        }
        for (int i = 1; i < n; i++) if (cnt[i] != 1) return false;
        return cnt[n] == 2;
    }
};

int main(){
    vector<int> nums = {2, 1, 3};
    // vector<int> nums = {1, 3, 3, 2};
    // vector<int> nums = {1, 1};
    // vector<int> nums = {3, 4, 4, 1, 2, 1};
    Solution S;
    cout << S.isGood(nums) << endl;
    return 0;
}