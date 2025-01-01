#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int left = (s[0] == '0');
        int right = 0;
        for (int i = 1; i < n; i++) right += (s[i] == '1');
        int ans = left + right;
        for (int i = 1; i < n-1; i++){
            left += (s[i] == '0');
            right -= (s[i] == '1');
            ans = max(ans, left + right);
        }
        return ans;
    }
};

int main(){
    string s = "011101";
    // string s = "00111";
    // string s = "1111";
    Solution S;
    cout << S.maxScore(s) << endl;
    return 0;
}