#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int v1 = 0;
        int v2 = 0;
        for (int num : nums){
            v2 = max(v2, min(v1, num));
            v1 = max(v1, num);
        }
        return (v1 - 1) * (v2 - 1);
    }
};

int main(){
    vector<int> nums = {3,4,5,2};
    // vector<int> nums = {1,5,4,5};
    // vector<int> nums = {3,7};
    Solution S;
    cout << S.maxProduct(nums) << endl;
    return 0;
}