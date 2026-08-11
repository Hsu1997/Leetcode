#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int n = nums.size();
        int l = 1;
        for (int i = 1; i < n; i++){
            if (nums[i] == nums[i-1] + 1) l++;
            else break;
        }
        int total = (nums[0] + nums[0] + l - 1) * l / 2;
        while(s.find(total) != s.end()) total++;
        return total;
    }
};

int main(){
    vector<int> nums = {1,2,3,2,5};
    // vector<int> nums = {3,4,5,1,12,14,13};
    // vector<int> nums = {38,44,45};
    Solution S;
    cout << S.missingInteger(nums) << endl;
    return 0;
}