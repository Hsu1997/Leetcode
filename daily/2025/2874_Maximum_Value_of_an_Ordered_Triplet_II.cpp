#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        long long M = 0;
        long long d = 0;
        for (int i = 0; i < n; i++){
            ans = max(ans, d * nums[i]);
            d = max(d, M - nums[i]);
            M = max(M, (long long)nums[i]);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {12,6,1,2,7};
    // vector<int> nums = {1,10,3,4,19};
    // vector<int> nums = {1,2,3};
    // vector<int> nums = {15,12,2,14,15,18,15,20,14,5,14,14,11,13,7};
    Solution S;
    cout << S.maximumTripletValue(nums) << endl;
    return 0;
}