#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int ans = 0;
    unordered_map<int,int> s;
    int c = 0;

    void dfs(vector<int>& nums, int k, int index){
        if (index >= nums.size()){
            if (c){
                // for (auto i : s) cout << i << " ";
                // cout << endl;
                ans++;
            }
            return;
        }
        if (s[nums[index]+k] == 0 && s[nums[index]-k] == 0){
            s[nums[index]]++;
            c++;
            dfs(nums, k, index+1);
            s[nums[index]]--;
            c--;
        }
        dfs(nums, k, index+1);
        return;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        dfs(nums, k, 0);
        return ans;
    }
};

int main(){
    vector<int> nums = {2,4,6};
    int k = 2;
    // vector<int> nums = {1};
    // int k = 1;
    // vector<int> nums = {10,4,5,7,2,1};
    // int k = 3;
    Solution S;
    cout << S.beautifulSubsets(nums, k) << endl;
    return 0;
}