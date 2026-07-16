#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b){
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mv = 0;
        vector<int> res(n);
        for (int i = 0; i < n; i++){
            mv = max(mv, nums[i]);
            res[i] = gcd(mv, nums[i]);
        }
        sort(res.begin(), res.end());
        long long ans = 0;
        for (int i = 0; i < n / 2; i++){
            ans += gcd(res[i], res[n-1-i]);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,6,4};
    // vector<int> nums = {3,6,2,8};
    Solution S;
    cout << S.gcdSum(nums) << endl;
    return 0;
}