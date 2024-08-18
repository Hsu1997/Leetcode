#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int one = 0;
        int zero = 0;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < n; right++){
            if (s[right] == '0') zero++;
            else one++;
            while(zero > k && one > k){
                if (s[left] == '0') zero--;
                else one--;
                left++;
            }
            ans += (right - left + 1);
        }
        return ans;
    }
};

int main(){
    string s = "10101";
    int k = 1;
    // string s = "1010101";
    // int k = 2;
    // string s = "11111";
    // int k = 1;
    Solution S;
    cout << S.countKConstraintSubstrings(s, k) << endl;
    return 0;
}