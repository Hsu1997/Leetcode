#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int s = *min_element(nums.begin(), nums.end());
        int e = *max_element(nums.begin(), nums.end());
        vector<int> ans;
        unordered_set<int> num(nums.begin(), nums.end());
        for (int i = s + 1; i < e; i++){
            if (num.find(i) == num.end()) ans.push_back(i);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,4,2,5};
    // vector<int> nums = {7,8,6,9};
    // vector<int> nums = {5,1};
    Solution S;
    vector<int> ans = S.findMissingElements(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}