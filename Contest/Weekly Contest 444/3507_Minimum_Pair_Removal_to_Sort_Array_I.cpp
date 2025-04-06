#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while(true){
            bool nondecreasing = true;
            int index = -1;
            int s = INT_MAX;
            for (int i = 0; i < nums.size() - 1; i++){
                if (nums[i] > nums[i+1]) nondecreasing = false;
                if (nums[i] + nums[i+1] < s){
                    s = nums[i] + nums[i+1];
                    index = i;
                }
            }
            if (nondecreasing) return ans;
            nums[index] += nums[index+1];
            nums.erase(nums.begin() + index + 1);
            ans++;
        }
        return 0;
    }
};

int main(){
    vector<int> nums = {5,2,3,1};
    // vector<int> nums = {1,2,2};
    Solution S;
    cout << S.minimumPairRemoval(nums) << endl;
    return 0;
}