#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int count = 0;
        int temp = 0;
        int multiple = 1;
        stack<pair<int, int>> S;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(' && s[i+1] == ')'){
                if (count == 0) ans++;
                else temp++;
                // cout << '(' << endl;
                i++;
            }
            else{
                if (s[i] == '('){
                    if (count == 0){
                        multiple *= 2;
                        count++;
                    }
                    else{
                        S.push(make_pair(temp, multiple));
                        count++;
                        temp = 0;
                        multiple = 2;
                    }
                }
                else{
                    count--;
                    if(count == 0){
                        ans += temp*multiple;
                        temp = 0;
                        multiple = 1;
                    }
                    else{
                        temp = temp * S.top().second + S.top().first;
                        multiple = S.top().second;
                        S.pop();
                    }
                }
            }
            // cout << s[i] << " : ans = " << ans << ", count = " << count << ", temp = " << temp << ", mul = " << multiple << endl;
        }
        return ans;
    }
};

int main(){
    // string s = "(()(()))";
    // 6
    // string s = "((()))";
    // 4
    string s = "(())(())"; 
    // 4
    Solution S;
    cout << S.scoreOfParentheses(s) << endl;
    return 0;
}