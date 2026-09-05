#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> score(n);
        int M = 0;
        for (int i = 0; i < n; i++){
            M = max(M, nums[i]);
            score[i] = M;
        }
        int m = INT_MAX;
        for (int i = n - 1; i >= 0; i--){
            m = min(m, nums[i]);
            score[i] -= m;
        }
        for (int i = 0; i < n; i++){
            if (score[i] <= k) return i;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {5,0,1,4};
    int k = 3;
    // vector<int> nums = {3,2,1};
    // int k = 1;
    // vector<int> nums = {0};
    // int k = 0;
    Solution S;
    cout << S.firstStableIndex(nums, k) << endl;
    return 0;
}