#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    bool check(vector<int>& nums, int limit, int m){
        int temp = 0;
        int group = 0;
        for (auto &i : nums){
            if (i > limit) return false;
            temp += i;
            if (temp > limit){
                temp = i;
                group++;
                if (group == m) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int m) {
        int min = numeric_limits<int>::max();
        int max = 0;
        for (auto &i : nums){
            max += i;
            if (i < min) min = i;
        }
        // cout << ", min = " << min << ", max = " << max << endl;
        while(min < max){
            // cout << "min = " << min << ", max = " << max << endl;
            // cout << "check " << min + (max - min)/2 << endl;
            if (!check(nums, min + (max - min)/2, m)){
                min = min + (max - min) / 2 + 1;
            } 
            else{
                max = min + (max - min) / 2;
            }
        }
        return min;
    }
};

int main(){
    // vector<int> nums = {7,2,5,10,8};
    vector<int> nums = {1,4,4};
    int m = 3;
    Solution S;
    cout << S.splitArray(nums, m) << endl;
    return 0;
}