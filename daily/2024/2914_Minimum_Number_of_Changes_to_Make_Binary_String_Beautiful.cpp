#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; i += 2){
            if (s[i] != s[i+1]) ans++;
        }
        return ans;
    }
};

int main(){
    string s = "1001";
    // string s = "10";
    // string s = "0000";
    Solution S;
    cout << S.minChanges(s) << endl;
    return 0;
}