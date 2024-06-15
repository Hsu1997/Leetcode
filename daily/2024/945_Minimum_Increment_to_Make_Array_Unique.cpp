#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int M = *max_element(nums.begin(), nums.end());
        vector<int> c(M+1, 0);
        for (int i : nums) c[i]++;
        int ans = 0;
        int acc = 0;
        for (int i = 0; i < c.size(); i++){
            acc = max(0, acc - 1 + c[i]);
            ans += acc;
        }
        if (acc) ans += acc*(acc-1)/2;
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,2,2};
    // vector<int> nums = {3,2,1,2,1,7};
    Solution S;
    cout << S.minIncrementForUnique(nums) << endl;
    return 0;
}