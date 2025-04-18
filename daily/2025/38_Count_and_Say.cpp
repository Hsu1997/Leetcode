#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n-1);
        int l = s.length();
        string ans = "";
        char last = s[0];
        int count = 0;
        for (int i = 0; i < l; i++){
            if (s[i] == last) count++;
            else{
                ans += to_string(count) + last;
                last = s[i];
                count = 1;
            }
        }
        ans += to_string(count) + last;
        return ans;
    }
};

int main(){
    int n = 4;
    // int n = 1;
    // int n = 15;
    // int n = 30;
    Solution S;
    cout << S.countAndSay(n) << endl;
    return 0;
}