#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Find the first value which greater equal than the target
        int n = nums.size();
        // a point to the position which is the last number less than target
        // b point to the position which is the first number greater than target
        int a = 0;
        int b = n-1;
        if (nums.at(a) >= target) return a;
        if (nums.at(b) == target) return b;
        if (nums.at(b) < target) return n;
        while (b-a > 1){
            if ( nums.at(a+(b-a)/2 ) < target){
                a = a+(b-a)/2;
            }
            else if ( nums.at(a+(b-a)/2) == target ){
                return a+(b-a)/2;
            }
            else {
                b = a+(b-a)/2;
            }
        }
        return b;
    }
};

int main(){
    int n[4] = {1,3,5,6};
    vector<int> nums(n, n + 4);
    Solution A;
    cout << A.searchInsert(nums, 5) << endl;
}