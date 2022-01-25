#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // require a vector for answer
        vector<int> ans;
        // add the limit to the two side
        nums.insert(nums.begin(), numeric_limits<int>::min());
        nums.push_back(numeric_limits<int>::max());
        // find the middle number
        vector<int>::iterator mid;
        for (mid = nums.begin(); mid != nums.end(); ++mid){
            if ( pow(*mid,2) < pow(*(mid+1), 2) ) break;
        }
        ans.push_back(pow(*mid,2));
        cout << pow(*mid,2) << " ";
        ;
        vector<int>::iterator a = mid-1;
        vector<int>::iterator b = mid+1;
        for (int n = nums.size()-3; n > 0; n--){
            if ( pow(*a,2) > pow(*b,2) ){
                ans.push_back(pow(*b,2));
                cout << pow(*b,2) << " ";
                b++;
            }
            else{
                ans.push_back(pow(*a,2));
                cout << pow(*a,2) << " ";
                a--;
            }
        }
        return ans;
    };
};

int main(){
    int n[5] = {-4,-1,0,3,10};
    vector<int> nums(n, n + 5);
    Solution A;
    A.sortedSquares(nums);
}