#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        s = " " + s + " ";
        int ans = 0;
        long acc = 0;
        int mod = 1e9+7;
        for (int i = 1; i < s.length(); i++){
            if (s[i] != s[i-1]){
                long temp = (acc * (acc + 1) / 2) % mod;
                ans = (ans + temp) % mod;
                acc = 1;
            }
            else acc++;
            // cout << "i = " << i << " : " << ans << endl;
        }
        return ans;
    }
};

int main(){
    string s = "abbcccaa";
    // string s = "xy";
    // string s = "zzzzz";
    Solution S;
    cout << S.countHomogenous(s) << endl;
    return 0;
}