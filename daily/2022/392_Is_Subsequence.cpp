#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s == "") return 1;
        string::iterator s_ptr = s.begin();
        for (string::iterator t_ptr = t.begin(); t_ptr != t.end(); t_ptr++){
            if (*t_ptr == *s_ptr) s_ptr++;
            if (s_ptr == s.end()) return 1;
        }
        return 0;
    }
};

int main(){
    Solution S;
    string s, t;
    cin >> s >> t;
    cout << S.isSubsequence(s,t) << endl;
    return 0;
}