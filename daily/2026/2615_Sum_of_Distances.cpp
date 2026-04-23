#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        unordered_map<int, pair<long long,long long>> m;
        for (int i = 0; i < n; i++){
            int curr = nums[i];
            if (m.find(curr) != m.end()){
                ans[i] += (1LL * m[curr].first * i - m[curr].second);
            }
            m[curr].first++;
            m[curr].second += i;
        }
        m.clear();
        for (int i = n - 1; i >= 0; i--){
            int curr = nums[i];
            if (m.find(curr) != m.end()){
                ans[i] += (m[curr].second - 1LL * m[curr].first * i);
            }
            m[curr].first++;
            m[curr].second += i;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,1,1,2};
    // vector<int> nums = {0,5,3};
    Solution S;
    vector<long long> ans = S.distance(nums);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}