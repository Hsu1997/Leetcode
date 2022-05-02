#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>::iterator ptr = nums.begin();
        for (vector<int>::iterator a = nums.begin(); a != nums.end(); a++){
            if (*a % 2 == 0) swap(*a, *ptr++);
        }
        return nums;
    }
};

int main(){
    vector<int> nums = {3,1,2,4};
    Solution S;
    for (auto i : S.sortArrayByParity(nums)) cout << i << " ";
    cout << endl;
    return 0;
}