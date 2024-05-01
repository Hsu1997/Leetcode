#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n * (n+1) / 2;
        for (int i : nums) ans -= i;
        return ans;
    }
};

int main(){
    vector<int> nums = {3,0,1};
    Solution S;
    cout << S.missingNumber(nums) << endl;
    return 0;
}