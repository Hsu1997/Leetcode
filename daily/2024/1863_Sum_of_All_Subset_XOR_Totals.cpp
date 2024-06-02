#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        vector<int> temp = {0};
        for (auto i : nums){
            int n = temp.size();
            while(n--){
                ans += i ^ temp[n];
                temp.push_back(i ^ temp[n]);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3};
    // vector<int> nums = {5,1,6};
    // vector<int> nums = {3,4,5,6,7,8};
    Solution S;
    cout << S.subsetXORSum(nums) << endl;
    return 0;
}