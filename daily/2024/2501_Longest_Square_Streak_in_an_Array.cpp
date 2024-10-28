#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> m;
        for (int i : nums){
            int root = sqrt(i);
            if (root * root == i) m[i] = m[root] + 1;
            else m[i] = 1;
        }
        int ans = 1;
        for (auto [n, c] : m){
            // cout << n << " " << c << endl;
            ans = max(ans, c);
        }
        return (ans == 1)? -1 : ans;
    }
};

int main(){
    vector<int> nums = {4,3,6,16,8,2};
    // vector<int> nums = {2,3,5,6,7};
    Solution S;
    cout << S.longestSquareStreak(nums) << endl;
    return 0;
}