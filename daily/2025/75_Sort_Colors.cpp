#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ptr = 0;
        while(ptr <= r){
            if (nums[ptr] == 0) swap(nums[l++], nums[ptr++]);
            else if (nums[ptr] == 1) ptr++;
            else swap(nums[ptr], nums[r--]);
        }
        return;
    }
};

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    // vector<int> nums = {2,0,1};
    // vector<int> nums = {1,0,1};
    // vector<int> nums = {0,2,2,2,0,2,1,1};
    Solution S;
    S.sortColors(nums);
    for (int i : nums) cout << i << " ";
    cout << endl;
    return 0;
}