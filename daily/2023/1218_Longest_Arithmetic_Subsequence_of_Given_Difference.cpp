#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 1;
        unordered_map<int,int> m;
        for (auto i : arr){
            m[i] = 1+ m[i - difference];
            ans = max(ans, m[i]);
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {1,2,3,4};
    int difference = 1;
    // vector<int> arr = {1,3,5,7};
    // int difference = 1;
    // vector<int> arr = {1,5,7,8,5,3,4,2,1};
    // int difference = -2;
    Solution S;
    cout << S.longestSubsequence(arr, difference) << endl;
    return 0;
}