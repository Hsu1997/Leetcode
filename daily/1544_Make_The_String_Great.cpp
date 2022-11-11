#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        if (s.length() < 2) return s;

        stack<char> sta;
        for (auto i : s){
            if (sta.empty()) sta.push(i);
            else{
                if (abs(i - sta.top()) == 32) sta.pop();
                else sta.push(i);
            }
        }
        string ans;
        while(!sta.empty()){
            ans += sta.top();
            sta.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution S;
    // string s = "leEeetcode";
    string s = "abBAcC";
    cout << S.makeGood(s) << endl;
    return 0;
}