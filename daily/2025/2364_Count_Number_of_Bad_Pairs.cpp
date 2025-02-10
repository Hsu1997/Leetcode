#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long ans = 0;
        unordered_map<int,int> count;
        for (int i = 0; i < n; i++){
            ans += count[nums[i] - i];
            count[nums[i] - i]++;
        }
        return n * (n-1) / 2 - ans;
    }
};

int main(){
    vector<int> nums = {4,1,3,3};
    // vector<int> nums = {1,2,3,4,5};
    Solution S;
    cout << S.countBadPairs(nums) << endl;
    return 0;
}