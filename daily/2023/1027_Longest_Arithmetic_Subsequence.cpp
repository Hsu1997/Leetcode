#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        // diff : <last num : count>
        unordered_map<int, unordered_map<int,int>> m;
        int ans = 2;

        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                int diff = nums[i] - nums[j];
                if (m[diff].count(j)){
                    m[diff][i] = m[diff][j] + 1;
                    ans = max(ans, m[diff][i]);
                }
                else m[diff][i] = 2;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {3,6,9,12};
    // vector<int> nums = {9,4,7,2,10};
    // vector<int> nums = {20,1,15,3,10,5,8};
    // vector<int> nums = {12,28,13,6,34,36,53,24,29,2,23,0,22,25,53,34,23,50,35,43,53,11,48,56,44,53,31,6,31,57,46,6,17,42,48,28,5,24,0,14,43,12,21,6,30,37,16,56,19,45,51,10,22,38,39,23,8,29,60,18};
    Solution S;
    cout << S.longestArithSeqLength(nums) << endl;
    return 0;
}