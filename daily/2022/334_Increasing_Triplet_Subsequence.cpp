#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;

        vector<int> inc;
        for (int i = 0; i < nums.size(); i++){
            auto it = lower_bound(inc.begin(), inc.end(), nums[i]);
            if (it == inc.end()) inc.push_back(nums[i]);
            else *it = nums[i];

            // for (auto j : inc) cout << j << " ";
            // cout << endl;

            if (inc.size() >= 3) return true;
        }
        return false;
    }
};

int main(){
    // vector<int> nums = {1,2,3,4,5};
    // vector<int> nums = {5,4,3,2,1};
    // vector<int> nums = {2,1,5,0,4,6};
    vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    Solution S;
    cout << S.increasingTriplet(nums) << endl;
    return 0;
}