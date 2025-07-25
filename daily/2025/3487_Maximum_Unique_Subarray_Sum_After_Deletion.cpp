#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = 0;
        int M = INT_MIN;
        unordered_map<int,int> cnt;
        for (int i : nums){
            if (cnt[i] == 0 && i >= 0) ans += i;
            cnt[i]++;
            M = max(M, i);
        }
        if (ans == 0) return M;
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5};
    // vector<int> nums = {1,1,0,1,1};
    // vector<int> nums = {1,2,-1,-2,1,0,-1};
    // vector<int> nums = {-1,-2,-1};
    Solution S;
    cout << S.maxSum(nums) << endl;
    return 0;
}