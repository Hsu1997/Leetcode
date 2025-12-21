#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (int i : nums) if (i % 3) ans++;
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    // vector<int> nums = {3,6,9};
    Solution S;
    cout << S.minimumOperations(nums) << endl;
    return 0;
}