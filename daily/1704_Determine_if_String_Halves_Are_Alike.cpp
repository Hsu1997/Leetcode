#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<char> vowel = {'a','e','i','o','u','A','E','I','O','U'};

    bool halvesAreAlike(string s) {
        int count = 0;
        for (int i = 0; i < s.length()/2; i++){
            if (vowel.find(s[i]) != vowel.end()) count++;
        }
        for (int i = s.length()/2; i < s.length(); i++){
            if (vowel.find(s[i]) != vowel.end()) count--;
        }
        return count == 0;
    }
};

int main(){
    string s = "book";
    // string s = "textbook";
    // string s = "AbCdEfGh";
    Solution S;
    cout << S.halvesAreAlike(s) << endl;
    return 0;
}