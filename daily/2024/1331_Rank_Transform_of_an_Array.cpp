#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        vector<int> nums = arr;
        sort(nums.begin(), nums.end());
        unordered_map<int,int> m;
        m[nums[0]] = 1;
        int index = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[i-1]) index++;
            m[nums[i]] = index;
        }
        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); i++) ans[i] = m[arr[i]];
        return ans;
    }
};

int main(){
    vector<int> arr = {40,10,20,30};
    // vector<int> arr = {100,100,100};
    // vector<int> arr = {37,12,28,9,100,56,80,5,12};
    // vector<int> arr = {};
    Solution S;
    vector<int> ans = S.arrayRankTransform(arr);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}