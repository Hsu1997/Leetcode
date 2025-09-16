#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        bool valid = true;
        unordered_set<char> s;
        for (char c : brokenLetters) s.insert(c);
        for (int i = 0; i < text.length(); i++){
            if (text[i] == ' '){
                ans += valid;
                valid = true;
            }
            else{
                if (s.find(text[i]) != s.end()) valid = false;
            }
        }
        ans += valid;
        return ans;
    }
};

int main(){
    string text = "hello world";
    string brokenLetters = "ad";
    // string text = "leet code";
    // string brokenLetters = "lt";
    // string text = "leet code";
    // string brokenLetters = "e";
    Solution S;
    cout << S.canBeTypedWords(text, brokenLetters) << endl;
    return 0;
}