#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) return false;
        char c1;
        char c2;
        int diff = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == goal[i]) continue;
            if (diff == 0){
                c1 = s[i];
                c2 = goal[i];
                diff++;
            }
            else if (diff == 1){
                if ((s[i] == c2 && goal[i] == c1) == false) return false;
                diff++;
            }
            else return false;
        }
        if (diff == 2) return true;
        if (diff == 1) return false;
        vector<int> c(26,0);
        for (auto i : s){
            if (c[i-'a']) return true;
            c[i-'a']++;
        }
        return false;
    }
};

int main(){
    // string s = "ab";
    // string goal = "ba";
    string s = "abcaa";
    string goal = "abcbb";
    Solution S;
    cout << S.buddyStrings(s, goal) << endl;
    return 0;
}