#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int total = 0;
    void subproblem(vector<int>& nums, int index, int curr){
        if (index == nums.size()){
            total += curr;
        }
        else{
            subproblem(nums, index+1, curr ^ nums[index]);
            subproblem(nums, index+1, curr);
        }

    }
    int subsetXORSum(vector<int>& nums) {
        subproblem(nums, 0, 0);
        return total;
    }
};

int main(){
    vector<int> nums = {1,3};
    // vector<int> nums = {5,1,6};
    // vector<int> nums = {3,4,5,6,7,8};
    Solution S;
    cout << S.subsetXORSum(nums) << endl;
    return 0;
}