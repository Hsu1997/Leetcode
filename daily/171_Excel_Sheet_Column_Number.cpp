#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (auto i : columnTitle){
            ans *= 26;
            ans += i - 'A' + 1;
            // cout << (int)i << endl;
        }
        return ans;
    }
};

int main(){
    // A ~ Z : 65 ~ 90
    string in = "FXSHRXW";
    Solution S;
    cout << S.titleToNumber(in) << endl;
    return 0;
}