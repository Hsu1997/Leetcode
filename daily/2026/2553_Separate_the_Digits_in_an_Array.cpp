#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--){
            int curr = nums[i];
            while(curr){
                ans.push_back(curr % 10);
                curr /= 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    vector<int> nums = {13,25,83,77};
    // vector<int> nums = {7,1,3,9};
    Solution S;
    vector<int> ans = S.separateDigits(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}