#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> complementarySum(2 * limit + 2, 0);
        for (int i = 0; i < n / 2; i++){
            int a = min(nums[i], nums[n-1-i]);
            int b = max(nums[i], nums[n-1-i]);
            // [a+b, a+b], cost - 2, also included in next period
            complementarySum[a + b] -= 1;
            complementarySum[a + b + 1] += 1;
            // [a+1, b+limit], cost - 1
            complementarySum[a + 1] -= 1;
            complementarySum[b + limit + 1] += 1;
        }
        int m = 0;
        int acc = 0;
        for (int i = 2; i <= 2 * limit; i++){
            acc += complementarySum[i];
            m = min(m, acc);
        }
        return n + m;
    }
};

int main(){
    vector<int> nums = {1,2,4,3};
    int limit = 4;
    // vector<int> nums = {1,2,2,1};
    // int limit = 2;
    // vector<int> nums = {1,2,1,2};
    // int limit = 2;
    // vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    // int limit = 1;
    Solution S;
    cout << S.minMoves(nums, limit) << endl;
    return 0;
}