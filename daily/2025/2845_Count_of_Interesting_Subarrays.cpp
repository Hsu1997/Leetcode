#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0;
        int n = nums.size();
        unordered_map<int,int> count;
        int acc = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] % modulo == k) acc++;
            acc %= modulo;
            count[acc]++;
        }
        acc = 0;
        for (int i = 0; i < n; i++){
            ans += count[(acc + k) % modulo];
            acc = (acc + (nums[i] % modulo == k)) % modulo;
            count[acc]--;
        }
        return ans;
    }
};
int main(){
    vector<int> nums = {3,2,4};
    int modulo = 2;
    int k = 1;
    // vector<int> nums = {3,1,9,6};
    // int modulo = 3;
    // int k = 0;
    // vector<int> nums = {11,12,21,31};
    // int modulo = 10;
    // int k = 1;
    Solution S;
    cout << S.countInterestingSubarrays(nums, modulo, k) << endl;
    return 0;
}