#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int num : nums){
            int count = 0;
            while(num){
                count++;
                num /= 10;
            }
            if (count % 2 == 0) ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {12,345,2,6,7896};
    // vector<int> nums = {555,901,482,1771};
    Solution S;
    cout << S.findNumbers(nums) << endl;
    return 0;
}