#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool same = true;
        for (int i = 1; i < n; i++){
            if (nums[i] != nums[i-1]){
                same = false;
                break;
            }
        }
        return (same)? 0 : 1;
    }
};

int main(){
    vector<int> nums = {1,2};
    // vector<int> nums = {5,5,5};
    Solution S;
    cout << S.minOperations(nums) << endl;
    return 0;
}