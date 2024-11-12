#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool is_prime(int n){
        for (int i = 2; i*i <= n; i++){
            if (n % i == 0) return false;
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime;
        for (int i = 2; i <= 1000; i++) if (is_prime(i)) prime.push_back(i);
        int n = nums.size();
        for (int i = n-2; i >= 0; i--){
            if (nums[i] < nums[i+1]) continue;
            int idx = 0;
            while(idx < prime.size() && prime[idx] <= nums[i] - nums[i+1]) idx++;
            if (idx == prime.size() || prime[idx] >= nums[i]) return false;
            nums[i] -= prime[idx];
        }
        // for (int i : nums) cout << i << " ";
        // cout << endl;
        return true;
    }
};

int main(){
    vector<int> nums = {4,9,6,10};
    // vector<int> nums = {6,8,11,12};
    // vector<int> nums = {5,8,3};
    Solution S;
    cout << S.primeSubOperation(nums) << endl;
    return 0;
}