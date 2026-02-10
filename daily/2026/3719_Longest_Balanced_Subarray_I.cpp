#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int start = 0; start < n; start++){
            unordered_map<int,int> cnt;
            int e = 0;
            int o = 0;
            for (int i = start; i < n; i++){
                cnt[nums[i]]++;
                if (cnt[nums[i]] == 1){
                    if (nums[i] % 2) o++;
                    else e++;
                }
                if (o == e) ans = max(ans, i - start + 1);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,5,4,3};
    // vector<int> nums = {3,2,2,5,4};
    // vector<int> nums = {1,2,3,2};
    Solution S;
    cout << S.longestBalanced(nums) << endl;
    return 0;
}