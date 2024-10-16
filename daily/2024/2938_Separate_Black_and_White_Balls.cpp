#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        int pos = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '0') ans += (i - pos++);
        }
        return ans;
    }
};

int main(){
    string s = "101";
    // string s = "100";
    // string s = "0111";
    Solution S;
    cout << S.minimumSteps(s) << endl;
    return 0;
}