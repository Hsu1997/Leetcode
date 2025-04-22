#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int last = 0;
        int ans = 0;
        for (int num : nums){
            if (num >= last){
                last = num;
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {4,2,5,3,5};
    // vector<int> nums = {1,2,3};
    Solution S;
    cout << S.maximumPossibleSize(nums) << endl;
    return 0;
}