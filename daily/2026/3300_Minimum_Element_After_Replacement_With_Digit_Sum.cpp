#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (int num : nums){
            int res = 0;
            while(num){
                res += num % 10;
                num /= 10;
            }
            ans = min(ans, res);
        }
        return ans;
    }
};

int main(){
    // vector<int> nums = {10,12,13,14};
    // vector<int> nums = {1,2,3,4};
    vector<int> nums = {999,19,199};
    Solution S;
    cout << S.minElement(nums) << endl;
    return 0;
}