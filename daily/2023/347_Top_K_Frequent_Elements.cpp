#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> count(20001,0);
        for (auto i : nums) count[i+10000]++;
        vector<int> s(100001);
        for (auto i : count) if (i) s[i]++;
        int temp = 100000;
        while(k) k -= s[temp--];
        vector<int> ans;
        for (int i = 0; i < 20001; i++) if (count[i] > 0 && count[i] > temp) ans.push_back(i-10000);
        return ans;
    }
};

int main(){
    // vector<int> nums = {1,1,1,2,2,3};
    // int k = 2;
    // vector<int> nums = {1};
    // int k = 1;
    vector<int> nums = {-1,-1};
    int k = 1;
    Solution S;
    vector<int> ans = S.topKFrequent(nums, k);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}