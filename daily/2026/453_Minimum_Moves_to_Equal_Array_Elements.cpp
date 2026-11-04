#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = INT_MAX;
        long long s = 0;
        for (int i : nums){
            m = min(m, i);
            s += i;
        }
        return s - 1LL * nums.size() * m;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    // vector<int> nums = {1,1,1};
    Solution S;
    cout << S.minMoves(nums) << endl;
    return 0;
}