#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();

        int ans = 1;

        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[ans-1]){
                nums[ans] = nums[i];
                ans++;
            }
        }

        return ans;
    }
};

int main(){
    Solution S;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << S.removeDuplicates(nums) << endl;
    for (auto i : nums) cout << i << " ";
    cout << endl;
    return 0;
}