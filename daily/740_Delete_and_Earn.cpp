#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int table[10001] = {0};
        int point[10001] = {0};
        for (int i : nums){
            table[i]++;
        }
        for (int i = 1; i < 10001; i++){
            table[i] *= i;
            // cout << table[i] << " ";
        }
        // cout << endl;
        point[1] = table[1];
        for (int i = 2; i < 10001; i++){
            point[i] = max(point[i-1], table[i] + point[i-2]);
            // cout << point[i] << " ";
        }
        return point[10000];
    }
};

int main(){
    vector<int> nums = {2,2,3,3,3,4};
    Solution S;
    cout << S.deleteAndEarn(nums) << endl;
    return 0;
}