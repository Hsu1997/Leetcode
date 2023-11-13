#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool is_vowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

    string sortVowels(string s) {
        unordered_map<char,int> count;
        for (char c : s) if (is_vowel(c)) count[c]++;
        // for (auto i : count) cout << i.first << " " << i.second << endl;
        int i = 0;
        int j = 0;
        string temp = "AEIOUaeiou";
        string ans;
        for (int k = 0; k < s.length(); k++){
            if (!is_vowel(s[k])) ans += s[k];
            else{
                while(count[temp[j]] == 0) j++;
                ans += temp[j];
                count[temp[j]]--;
            }
        }
        return ans;
    }
};

int main(){
    string s = "lEetcOde";
    Solution S;
    cout << S.sortVowels(s) << endl;
    return 0;
}