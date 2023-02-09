#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int round = 0;
        int candidate = 0;
        int destination = nums[0];
        while(destination < n-1){
            round++;
            for (int i = candidate; i <= destination; i++){
                candidate = max(candidate, i+nums[i]);
                if (candidate >= n-1) return round+1;
            }
            swap(candidate, destination);
        }
        return round+1;
    }
};

int main(){
    vector<int> nums = {2,3,1,1,4};
    // vector<int> nums = {2,3,0,1,4};
    Solution S;
    cout << S.jump(nums) << endl;
    return 0;
}