#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool is_vowel(char c){
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }
    string sortVowels(string s) {
        string vowel = "AEIOUaeiou";
        unordered_map<char, int> cnt;
        for (char c : s){ if (is_vowel(c)) cnt[c]++;}
        int ptr = 0;
        for (int i = 0; i < s.length(); i++){
            if (is_vowel(s[i])){
                while(cnt[vowel[ptr]] == 0) ptr++;
                s[i] = vowel[ptr];
                cnt[vowel[ptr]]--;
            }
            else continue;
        }
        return s;
    }
};

int main(){
    string s = "lEetcOde";
    // string s = "lYmpH";
    Solution S;
    cout << S.sortVowels(s) << endl;
    return 0;
}