#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        int carry = 0;
        for (int i = s.length() - 1; i > 0; i--){
            if (carry + s[i] - '0' == 0) ans++;
            else{
                ans += (carry + s[i] - '0') % 2;
                carry = 1;
                ans++;
            }
            // cout << "i = " << i << ", ans = " << ans << ", carry = " << carry << endl;
        }
        ans += carry;
        return ans;
    }
};

int main(){
    string s = "1101";
    // string s = "10";
    // string s = "1";
    Solution S;
    cout << S.numSteps(s) << endl;
    return 0;
}