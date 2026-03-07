#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        vector<vector<int>> prefix(2, vector<int>(n, 0));
        prefix[0][0] = (s[0] == '1');
        prefix[1][0] = (s[0] == '0');
        for (int i = 1; i < n; i++){
            prefix[0][i] = prefix[0][i-1] + (s[i] != ((i % 2 == 0)? '0' : '1'));
            prefix[1][i] = prefix[1][i-1] + (s[i] != ((i % 2 == 0)? '1' : '0'));
        }
        int ans = min(prefix[0][n-1], prefix[1][n-1]);
        if (n % 2 == 0) return ans;
        int endzero = 0;
        int endone = 0;
        for (int i = n - 1; i > 0; i--){
            endzero += s[i] != ((i % 2 == 0)? '0' : '1');
            endone += s[i] != ((i % 2 == 0)? '1' : '0');
            ans = min({ans, endzero + prefix[1][i-1], endone + prefix[0][i-1]});
        }
        return ans;
    }
};

int main(){
    string s = "111000";
    // string s = "010";
    // string s = "1110";
    // string s = "01001001101";
    Solution S;
    cout << S.minFlips(s) << endl;
    return 0;
}