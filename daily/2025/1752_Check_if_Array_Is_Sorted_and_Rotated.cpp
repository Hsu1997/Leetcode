#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool reset = false;
        for (int i = 0; i < n; i++){
            if (nums[i] > nums[(i+1)%n]){
                if (reset) return false;
                else reset = true;
            }
        }
        return true;
    }
};

int main(){
    vector<int> nums = {3,4,5,1,2};
    // vector<int> nums = {2,1,3,4};
    // vector<int> nums = {1,2,3};
    // vector<int> nums = {6,10,6};
    Solution S;
    cout << S.check(nums) << endl;
    return 0;
}