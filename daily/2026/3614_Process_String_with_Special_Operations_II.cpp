#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        long long l = 0;
        for (char c : s){
            if (c == '*'){
                if (l > 0) l--;
            }
            else if (c == '#'){
                l *= 2;
            }
            else if (c == '%'){
                continue;
            }
            else{
                l++;
            }
        }
        if (k >= l) return '.';
        for (int i = s.length()-1; i >= 0; i--){
            char c = s[i];
            // if (c >= 'a' && c <= 'z' && k < pure.length()) return pure[k];
            if (c == '*') l++;
            else if (c == '#'){
                l /= 2;
                if (k >= l) k -= l;
            }
            else if (c == '%'){
                k = (l - 1) - k;
            }
            else{
                if (k == l - 1) return c;
                l--;
            }
        }
        return '-';
    }
};

int main(){
    string s = "a#b%*";
    long long k = 1;
    // string s = "cd%#*#";
    // long long k = 3;
    // string s = "z*#";
    // long long k = 0;
    Solution S;
    cout << S.processStr(s, k) << endl;
    return 0;
}

// c.
// cd.
// dc
// dcdc
// dcd
// dcddcd 