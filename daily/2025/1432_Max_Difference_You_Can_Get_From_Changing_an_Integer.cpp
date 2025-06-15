#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string t = s;
        int n = s.length();
        int idx = 0;
        while(idx < n && s[idx] == '9') idx++;
        char c = s[idx];
        if (idx < n) replace(s.begin(), s.end(), c, '9');
        if (t[0] != '1'){
            c = t[0];
            replace(t.begin(), t.end(), c, '1');
        }
        else{
            idx = 1;
            while(idx < n && (t[idx] == '1' || t[idx] == '0')) idx++;
            c = t[idx];
            replace(t.begin(), t.end(), c, '0');
        }
        // cout << s << " " << t << endl;
        return stoi(s) - stoi(t);
    }
};

int main(){
    int num = 555;
    // int num = 9;
    // int num = 1919;
    Solution S;
    cout << S.maxDiff(num) << endl;
    return 0;
}