#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x){
        int n = nums.size();
        int ans = numeric_limits<int>::max();
        vector<int> left(n+1, 0);
        vector<int> right(n+1, 0);
        for (int i = 1; i <= n; i++) left[i] = left[i-1] + nums[i-1];
        for (int i = 1; i <= n; i++) right[i] = right[i-1] + nums[n-i];
        
        // for (auto i : left) cout << i << " ";
        // cout << endl;
        // for (auto i : right) cout << i << " ";
        // cout << endl;

        int i = 0;
        int j = n;
        while(i <= n && j >= 0 && i+j <= n){
            if (left[i] +  right[j] == x){
                ans = min(ans, i+j);
                i++;
                j--;
            }
            else if (left[i] +  right[j] < x) i++;
            else j--;
        }

        return (ans == numeric_limits<int>::max())? -1:ans;
    }
};

int main(){
    vector<int> nums = {1,1,4,2,3};
    int x = 5;
    // vector<int> nums = {2,3,1,1,1};
    // int x = 5;
    Solution S;
    cout << S.minOperations(nums, x) << endl;
    return 0;
}