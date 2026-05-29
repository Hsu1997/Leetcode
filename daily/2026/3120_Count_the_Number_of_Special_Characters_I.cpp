#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnts[26] = {0};
        int cntl[26] = {0};
        for (char c : word){
            if (c >= 'a' && c <= 'z') cnts[c - 'a']++;
            else cntl[c - 'A']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++){
            if (cnts[i] > 0 && cntl[i] > 0) ans++;
        }
        return ans;
    }
};

int main(){
    string word = "aaAbcBC";
    // string word = "abc";
    // string word = "abBCab";
    Solution S;
    cout << S.numberOfSpecialChars(word) << endl;
    return 0;
}