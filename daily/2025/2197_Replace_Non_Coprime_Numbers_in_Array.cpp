#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b){
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> s;
        for (int curr : nums){
            while(!s.empty() && gcd(curr, s.top()) > 1){
                curr = curr / gcd(curr, s.top()) * s.top();
                s.pop();
            }
            s.push(curr);
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    vector<int> nums = {6,4,3,2,7,6,2};
    // vector<int> nums = {2,2,1,1,3,3,3};
    // vector<int> nums = {287,41,49,287,899,23,23,20677,5,825};
    Solution S;
    vector<int> ans = S.replaceNonCoprimes(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}