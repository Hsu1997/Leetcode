#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        string op = (x > y)? "ab" : "ba";
        int ans = 0;
        stack<char> sta;
        for (int i = 0; i < n; i++){
            if (!sta.empty() && sta.top() == op[0] && s[i] == op[1]){
                sta.pop();
                ans += max(x, y);
            }
            else{
                sta.push(s[i]);
            }
        }
        stack<char> sta2;
        while(!sta.empty()){
            if (!sta2.empty() && sta2.top() == op[0] && sta.top() == op[1]){
                sta2.pop();
                ans += min(x, y);
            }
            else{
                sta2.push(sta.top());
            }
            sta.pop();
        }
        return ans;
    }
};

int main(){
    string s = "cdbcbbaaabab";
    int x = 4;
    int y = 5;
    // string s = "aabbaaxybbaabb";
    // int x = 5;
    // int y = 4;
    // string s = "aabbabkbbbfvybssbtaobaaaabataaadabbbmakgabbaoapbbbbobaabvqhbbzbbkapabaavbbeghacabamdpaaqbqabbjbababmbakbaabajabasaabbwabrbbaabbafubayaazbbbaababbaaha";
    // int x = 1926;
    // int y = 4320;
    Solution S;
    cout << S.maximumGain(s, x, y) << endl;
    return 0;
}