#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool is_vowel(char c){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        else return false;
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int ans = 0;
        int count = 0;
        for (int i = 0; i < k && i < n; i++) if (is_vowel(s[i])) count++;
        ans = count;
        for (int i = k; i < n; i++){
            if (is_vowel(s[i])) count++;
            if (is_vowel(s[i-k])) count--;
            ans = max(ans, count);
        }
        return ans;
    }
};

int main(){
    // string s = "abciiidef";
    // int k = 3;
    // string s = "aeiou";
    // int k = 2;
    string s = "leetcode";
    int k = 3;
    Solution S;
    cout << S.maxVowels(s, k) << endl;
    return 0;
}