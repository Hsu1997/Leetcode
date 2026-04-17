#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int reverseNum(int x){
        int res = 0;
        while(x){
            res = res * 10 + (x % 10);
            x /= 10;
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++){
            if (m.find(nums[i]) != m.end()){
                ans = min(ans, i - m[nums[i]]);
            }
            m[reverseNum(nums[i])] = i;
        }
        return (ans == INT_MAX)? -1 : ans;
    }
};

int main(){
    vector<int> nums = {12,21,45,33,54};
    // vector<int> nums = {120,21};
    // vector<int> nums = {21,120};
    Solution S;
    cout << S.minMirrorPairDistance(nums) << endl;
    return 0;
}