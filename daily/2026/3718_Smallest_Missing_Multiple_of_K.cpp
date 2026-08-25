#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = k;
        while(s.find(res) != s.end()) res += k;
        return res;
    }
};

int main(){
    vector<int> nums = {8,2,3,4,6};
    int k = 2;
    // vector<int> nums = {1,4,7,10,15};
    // int k = 5;
    Solution S;
    cout << S.missingMultiple(nums, k) << endl;
    return 0;
}