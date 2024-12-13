#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        stack<int> s;
        for (int i : nums){
            if (s.empty() || i < s.top()) s.push(i);
            else{
                while(!s.empty()){
                    ans += s.top();
                    s.pop();
                    if (!s.empty()) s.pop();
                }
            }
        }
        while(!s.empty()){
            ans += s.top();
            s.pop();
            if (!s.empty()) s.pop();
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,1,3,4,5,2};
    // vector<int> nums = {2,3,5,1,3,2};
    Solution S;
    cout << S.findScore(nums) << endl;
    return 0;
}