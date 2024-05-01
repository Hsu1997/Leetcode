#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.length() == 0) return 0;
        int ans = 0;
        // for all character being center, need to consider even and odd size string
        for (int i = 0; i < s.length(); i++){
            int j = i - 1; 
            int k = i;
            // for every even size string, they have duplicate chracters.
            while(k < s.length()-1 && s[k] == s[k+1]) k++;
            // k is the last element with same character
            ans += (k - j)*(k - j + 1) / 2;
            // after loop, i will plus 1
            i = k;
            k++;
            while(j >= 0 && k < s.length() && s[j] == s[k]){
                ans++;
                j--;
                k++;
            }
        }
        return ans;
    }
};

int main(){
    string s = "abc";
    Solution S;
    cout << S.countSubstrings(s) << endl;
    return 0;
}