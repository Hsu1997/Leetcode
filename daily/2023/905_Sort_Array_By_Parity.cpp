#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        auto i = nums.begin();
        auto j = nums.end()-1;
        while(i < j){
            if (*i % 2 == 1) swap(*i, *j), j--;
            else i++;
        }
        return nums;
    }
};

int main(){
    vector<int> nums = {3,1,2,4};
    // vector<int> nums = {0};
    Solution S;
    vector<int> ans = S.sortArrayByParity(nums);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}