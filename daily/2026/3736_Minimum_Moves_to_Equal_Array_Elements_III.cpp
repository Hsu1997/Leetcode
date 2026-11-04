#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int M = 0;
        int sum = 0;
        for (int i : nums){
            M = max(M, i);
            sum += i;
        }
        return M * nums.size() - sum;
    }
};

int main(){
    vector<int> nums = {2,1,3};
    // vector<int> nums = {4,4,5};
    Solution S;
    cout << S.minMoves(nums) << endl;
    return 0;
}