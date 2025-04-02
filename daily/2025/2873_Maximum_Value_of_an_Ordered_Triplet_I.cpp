#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        long long M = 0;
        long long m = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            ans = max({ans, M * nums[i], m * nums[i]});
            for (int j = 0; j < i; j++){
                M = max(M, (long long)nums[j] - nums[i]);
                m = min(m, (long long)nums[j] - nums[i]);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {12,6,1,2,7};
    // vector<int> nums = {1,10,3,4,19};
    // vector<int> nums = {1,2,3};
    Solution S;
    cout << S.maximumTripletValue(nums) << endl;
    return 0;
}