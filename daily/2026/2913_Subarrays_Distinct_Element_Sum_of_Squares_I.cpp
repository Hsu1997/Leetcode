#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            unordered_map<int,int> cnt;
            for (int j = i; j < n; j++){
                cnt[nums[j]]++;
                ans += cnt.size() * cnt.size();
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,1};
    // vector<int> nums = {1,1};
    Solution S;
    cout << S.sumCounts(nums) << endl;
    return 0;
}