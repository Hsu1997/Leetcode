#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int ptr1 = 0;
        int ptr2 = n - 1;
        ans[ptr1] = nums[0];
        ans[ptr2] = nums[1];
        for (int i = 2; i < n; i++){
            if (ans[ptr1] > ans[ptr2]){
                ans[++ptr1] = nums[i];
            }
            else{
                ans[--ptr2] = nums[i];
            }
        }
        reverse(ans.begin() + ptr2, ans.end());
        return ans;
    }
};

int main(){
    vector<int> nums = {2,1,3};
    // vector<int> nums = {5,4,3,8};
    Solution S;
    vector<int> ans = S.resultArray(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}