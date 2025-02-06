#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> count;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                count[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for (auto& [mul, c] : count) ans += c * (c-1) / 2;
        return ans * 8;
    }
};

int main(){
    vector<int> nums = {2,3,4,6};
    // vector<int> nums = {1,2,4,5,10};
    Solution S;
    cout << S.tupleSameProduct(nums) << endl;
    return 0;
}