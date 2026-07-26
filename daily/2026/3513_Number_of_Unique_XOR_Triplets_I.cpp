#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;
        return (1 << (32 - __builtin_clz(n)));
    }
};

int main(){
    vector<int> nums = {1,2};
    // vector<int> nums = {3,1,2};
    // vector<int> nums = {3,1,2,4,5,6,7,8,9};
    // vector<int> nums = {3,1,2,10,9,8,7,6,5,4};
    // vector<int> nums = {3,1,2,10,9,8,7,6,5,4,11,12,13,14};
    Solution S;
    cout << S.uniqueXorTriplets(nums) << endl;
    return 0;
}