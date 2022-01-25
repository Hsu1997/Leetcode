#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void print(vector<int> &nums);
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator A, B;
        int temp;
        // B for the first number which is not zero
        for (B = nums.begin(); B != nums.end(); B++){
            if(*B != 0) break;
        }
        // if all vector elements are 0
        if (B == nums.end()) return;
        for (A = nums.begin(); A != nums.end(); A++){
            if (*A == 0){
                // print(nums);
                temp = *A;
                *A = *B;
                *B = temp;
                // print(nums);
                B++;
                while (B != nums.end()){
                    if (*B != 0) break;
                    B++;
                }
                if (B == nums.end()) return;
            }
            else if (A == B){
                B++;
                while (B != nums.end()){
                    if (*B != 0) break;
                    B++;
                }
                if (B == nums.end()) return;
            }
        }
    }
};

void Solution::print(vector<int> &nums){
    for (auto &it : nums){
        cout << it << " ";
    }
    cout << endl;
}

int main(){
    int n[5] = {0,1,0,3,12};
    vector<int> nums(n, n + sizeof(n) / sizeof(n[0]));
    Solution A;
    A.moveZeroes(nums);
    A.print(nums);
}