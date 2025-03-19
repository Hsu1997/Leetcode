#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> count;
        for (int i : nums) count[i]++;
        for (auto [num, c] : count) if (c % 2) return false;
        return true;
    }
};

int main(){
    vector<int> nums = {3,2,3,2,2,2};
    // vector<int> nums = {1,2,3,4};
    Solution S;
    cout << S.divideArray(nums) << endl;
    return 0;
}