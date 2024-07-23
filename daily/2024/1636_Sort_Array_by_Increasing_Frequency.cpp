#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> count;
        for (int i : nums) count[i]++;
        sort(nums.begin(), nums.end(), [&](int& a, int&b){return (count[a] == count[b])? a > b : count[a] < count[b];});
        return nums;
    }
};

int main(){
    vector<int> nums = {1,1,2,2,2,3};
    // vector<int> nums = {2,3,1,3,2};
    // vector<int> nums = {-1,1,-6,4,5,-6,1,4,1};
    Solution S;
    vector<int> ans = S.frequencySort(nums);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}