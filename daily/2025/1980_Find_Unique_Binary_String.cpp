#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans(n, '0');
        for (int i = 0; i < n; i++){
            if (nums[i][i] == '0') ans[i] = '1';
        }
        return ans;
    }
};

int main(){
    vector<string> nums = {"01","10"};
    // vector<string> nums = {"00","01"};
    // vector<string> nums = {"111","011","001"};
    Solution S;
    cout << S.findDifferentBinaryString(nums) << endl;
    return 0;
}