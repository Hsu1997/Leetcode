#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> count;
        for (int i : nums) count[i]++;
        for (auto [n, k] : count){
            if (count.find(n+1) != count.end()){
                ans = max(ans, count[n] + count[n+1]);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,2,2,5,2,3,7};
    // vector<int> nums = {1,2,3,4};
    // vector<int> nums = {1,1,1,1};
    // vector<int> nums = {1,3,5,7,9,11,13,15,17};
    Solution S;
    cout << S.findLHS(nums) << endl;
    return 0;
}
