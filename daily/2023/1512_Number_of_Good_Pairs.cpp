#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        vector<int> c(101);
        for (int i : nums) c[i]++;
        for (int i : nums) ans += --c[i];
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,1,1,3};
    // vector<int> nums = {1,1,1,1};
    // vector<int> nums = {1,2,3};
    Solution S;
    cout << S.numIdenticalPairs(nums) << endl;
    return 0;
}