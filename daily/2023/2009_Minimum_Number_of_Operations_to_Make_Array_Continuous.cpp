#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> repeat(n, 0);
        unordered_set<int> s;
        s.insert(nums[0]);
        for (int i = 1; i < n; i++){
            repeat[i] = repeat[i-1];
            if (s.find(nums[i]) != s.end()) repeat[i]++;
            s.insert(nums[i]);
        }
        // for (auto i : nums) cout << i << " ";
        // cout << endl;
        // for (auto i : repeat) cout << i << " ";
        // cout << endl;
        int ans = n-1;
        for (int start = 0; start < n-1; start++){
            // find the first position larger than target
            int target = nums[start] + (n - 1);
            int pos = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            int change = repeat[pos-1] - repeat[max(0, start-1)] + start + (n - pos);
            ans = min(ans, change);
        }
        return ans;
    }
};

int main(){
    // vector<int> nums = {4,2,5,3};
    // vector<int> nums = {1,2,3,5,6};
    // vector<int> nums = {1,10,100,1000};
    // vector<int> nums = {1,2,3,10,20};
    vector<int> nums = {41,33,29,33,35,26,47,24,18,28};
    Solution S;
    cout << S.minOperations(nums) << endl;
    return 0;
}