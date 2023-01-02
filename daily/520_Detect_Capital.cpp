#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int letter_case(char c){
        if (c >= 'A' && c <= 'Z') return 1;
        else if (c >= 'a' && c <= 'z') return 2;
        else return 0;
    }

    bool detectCapitalUse(string word) {
        if (word.length() < 2) return true;
        if (letter_case(word[0]) == 1 && letter_case(word[1]) == 1){
            for (int i = 2; i < word.length(); i++) if (letter_case(word[i]) != 1) return false;
        }
        else if (letter_case(word[0]) == 1 && letter_case(word[1]) == 2){
            for (int i = 2; i < word.length(); i++) if (letter_case(word[i]) != 2) return false;
        }
        else{
            for (int i = 1; i < word.length(); i++) if (letter_case(word[i]) != 2) return false;
        }
        return true;
    }
};

int main(){
    // string word = "USA";
    // string word = "FlaG";
    string word = "mL";
    Solution S;
    cout << S.detectCapitalUse(word) << endl;
    return 0;
}