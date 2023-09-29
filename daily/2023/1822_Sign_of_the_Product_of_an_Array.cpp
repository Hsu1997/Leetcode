#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (auto i : nums){
            if (i == 0) return 0;
            if (i < 0) ans *= -1;
        }
        return ans;
    }
};

int main(){
    // vector<int> nums = {-1,-2,-3,-4,3,2,1};
    // vector<int> nums = {1,5,0,2,-3};
    vector<int> nums = {-1,1,-1,1,-1};
    Solution S;
    cout << S.arraySign(nums) << endl;
    return 0;
}