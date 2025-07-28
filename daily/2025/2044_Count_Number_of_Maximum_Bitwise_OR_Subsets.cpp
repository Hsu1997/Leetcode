#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for (int i : nums) target |= i;
        unordered_map<int,int> cnt;
        for (int i : nums){
            unordered_map<int,int> temp;
            for (auto& [n, c] : cnt){
                temp[n | i] += c;
            }
            temp[i] += 1;
            for (auto& [n, c] : temp){
                cnt[n] += c;
            }
        }
        return cnt[target];
    }
};

int main(){
    vector<int> nums = {3,1};
    // vector<int> nums = {2,2,2};
    // vector<int> nums = {3,2,1,5};
    Solution S;
    cout << S.countMaxOrSubsets(nums) << endl;
    return 0;
}