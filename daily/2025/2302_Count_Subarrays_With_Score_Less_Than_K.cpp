#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long acc = 0;
        long long temp = 0;
        long long ans = 0;
        int start = 0;
        int n = nums.size();
        for (int end = 0; end < n; end++){
            acc += nums[end];
            temp += acc + 1LL * (end - start) * nums[end];
            while(temp >= k){
                temp -= acc + 1LL * (end - start) * nums[start];
                acc -= nums[start];
                start++;
            }
            ans += (end - start + 1);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,1,4,3,5};
    long long k = 10;
    // vector<int> nums = {1,1,1};
    // long long k = 5;
    Solution S;
    cout << S.countSubarrays(nums, k) << endl;
    return 0;
}