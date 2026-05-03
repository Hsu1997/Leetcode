#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        s = s + s;
        for (int i = 0; i < n; i++){
            if (s.substr(i, n) == goal) return true;
        }
        return false;
    }
};

int main(){
    string s = "abcde";
    string goal = "cdeab";
    // string s = "abcde";
    // string goal = "abced";
    Solution S;
    cout << S.rotateString(s, goal) << endl;
    return 0;
}