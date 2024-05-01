#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// class Solution {
// public:
//     int maxResult(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> dp(k+1, INT_MIN);
//         // multiset will record multi times of the same numbers.
//         multiset<int> S;
//         dp[0] = nums[0];
//         S.insert(nums[0]);

//         for (int i = 1; i < n; i++){
//             // erase(find()) will erase the first number of the multi numbers.
//             if (i > k) S.erase(S.find(dp[i%(k+1)]));
//             dp[i%(k+1)] = *S.rbegin() + nums[i];
//             S.insert(dp[i%(k+1)]);
//         }
//         return dp[(n-1) % (k+1)];
//     }
// };

class Solution {
public:
    int maxResult(vector<int>& nums, int k){
        vector<int> dp(k+1, INT_MIN);
        dp[0] = nums[0];
        deque Q({0});

        for (int i = 1; i < nums.size(); i++){
            if (Q.front() < i-k) Q.pop_front();
            dp[i%(k+1)] = nums[i] + dp[Q.front() % (k+1)];
            // always search from back and we can have the order from bigger to smaller.
            while(!Q.empty() && dp[Q.back()%(k+1)] <= dp[i%(k+1)]) Q.pop_back();
            Q.push_back(i);
        }

        return dp[(nums.size()-1) % (k+1)];
    }
};

int main(){
    // vector<int> nums = {1,-1,-2,4,-7,3};
    // int k = 2;
    // vector<int> nums = {10,-5,-2,4,0,3};
    // int k = 3;
    // vector<int> nums = {1,-5,-20,4,-1,3,-6,-3};
    // int k = 2;
    vector<int> nums = {100,-1,-100,-1,100};
    int k = 2;
    Solution S;
    cout << S.maxResult(nums, k) << endl;
    return 0;
}