#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for (int i = 0; i < n; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,5,1,3,4,7};
    int n = 3;
    // vector<int> nums = {1,2,3,4,4,3,2,1};
    // int n = 4;
    // vector<int> nums = {1,1,2,2};
    // int n = 2;
    Solution S;
    vector<int> ans = S.shuffle(nums, n);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}