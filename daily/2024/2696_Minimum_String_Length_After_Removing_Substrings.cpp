#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> sta;
        for (char c : s){
            if (sta.empty() || (c != 'B' && c != 'D')) sta.push(c);
            else{
                if (c == 'B' && sta.top() == 'A') sta.pop();
                else if (c == 'D' && sta.top() == 'C') sta.pop();
                else sta.push(c);
            }
        }
        return sta.size();
    }
};

int main(){
    string s = "ABFCACDB";
    // string s = "ACBBD";
    Solution S;
    cout << S.minLength(s) << endl;
    return 0;
}