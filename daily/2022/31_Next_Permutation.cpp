#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;
        vector<int>::iterator find = nums.end() - 2;
        while(*find >= *(find+1) && find > nums.begin()){
            find--;
        }
        if (find == nums.begin() && *find > *(find+1)) return reverse(nums.begin(), nums.end());
        reverse((find + 1), nums.end());

        for (vector<int>::iterator i = find + 1; i < nums.end(); i++){
            if (*i > *find){
                swap(*i, *find);
                return;
            }
        }
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution S;
    S.nextPermutation(nums);
    for (auto i : nums) cout << i << " ";
    cout << endl;
}