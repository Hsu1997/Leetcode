#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        int count = 0;
        for (auto num : nums){
            if (count == 0) majority = num;
            if (num == majority) count++;
            else count--;
        }
        return majority;
    }
};

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    Solution A;
    cout << A.majorityElement(nums) << endl;
    return 0;
}