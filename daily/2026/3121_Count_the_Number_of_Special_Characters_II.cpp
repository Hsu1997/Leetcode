#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt[26] = {0};
        for (char c : word){
            if (c >= 'a' && c <= 'z'){
                if (cnt[c - 'a'] == 0) cnt[c - 'a'] = 1;
                else if (cnt[c - 'a'] == 2) cnt[c - 'a'] = -1;
                else continue;
            }
            else{
                if (cnt[c - 'A'] == 0) cnt[c - 'A'] = -1;
                else if (cnt[c - 'A'] == 1) cnt[c - 'A'] = 2;
                else continue;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) if (cnt[i] == 2) ans++;
        return ans;
    }
};

int main(){
    string word = "aaAbcBC";
    // string word = "abc";
    // string word = "AbBCab";
    Solution S;
    cout << S.numberOfSpecialChars(word) << endl;
    return 0;
}