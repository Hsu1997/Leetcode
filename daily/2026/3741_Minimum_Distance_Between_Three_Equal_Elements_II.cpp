#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<vector<int>> table(n + 1);
        for (int i = 0; i < n; i++){
            table[nums[i]].push_back(i);
        }
        for (auto& v : table){
            if (v.size() >= 3){
                for (int i = 2; i < v.size(); i++){
                    ans = min(ans, (v[i] - v[i-2]) * 2);
                }
            }
        }
        return (ans == INT_MAX)? -1 : ans;
    }
};

int main(){
    vector<int> nums = {1,2,1,1,3};
    // vector<int> nums = {1,1,2,3,2,1,2};
    // vector<int> nums = {1};
    Solution S;
    cout << S.minimumDistance(nums) << endl;
    return 0;
}