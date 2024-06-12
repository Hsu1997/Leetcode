#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int white = 0;
        int red = 0;
        int blue = nums.size()-1;
        while(white <= blue){
            if (nums[white] == 0) swap(nums[white++], nums[red++]);
            else if (nums[white] == 1) white++;
            else swap(nums[white], nums[blue--]);
        }
    }
};

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    // vector<int> nums = {2,0,1};
    Solution S;
    S.sortColors(nums);
    for (auto i : nums) cout << i << " ";
    cout << endl;
    return 0;
}