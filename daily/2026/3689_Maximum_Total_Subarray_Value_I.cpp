#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int M = INT_MIN;
        int m = INT_MAX;
        for (int i : nums){
            M = max(M, i);
            m = min(m, i);
        }
        long long ans = M - m;
        ans *= k;
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,2};
    int k = 2;
    // vector<int> nums = {4,2,5,1};
    // int k = 3;
    Solution S;
    cout << S.maxTotalValue(nums, k) << endl;
    return 0;
}