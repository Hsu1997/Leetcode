#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return 0;
        unordered_map<int,int> m;
        m[nums[0]] += 1;
        m[-nums[0]] += 1;
        for (int i = 1; i < n; i++){
            int curr = nums[i];
            unordered_map<int,int> temp;
            for (auto k : m){
                int val = k.first;
                int count = k.second;
                temp[val+curr] += count;
                temp[val-curr] += count;
            }
            swap(m, temp);
        }
        return m[target];
    }
};

int main(){
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    // vector<int> nums = {1};
    // int target = 1;
    // vector<int> nums = {0,0,0,0,0,0,0,0,1};
    // int target = 1;

    Solution S;
    cout << S.findTargetSumWays(nums, target) << endl;
    return 0;
}