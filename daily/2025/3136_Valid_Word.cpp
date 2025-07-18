#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;
        int vowel = 0;
        int consonant = 0;
        for (char c : word){
            if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) return false;
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowel++;
                else consonant++;
            }
        }
        return vowel > 0 && consonant > 0;
    }
};

int main(){
    string word = "234Adas";
    // string word = "b3";
    // string word = "a3$e";
    Solution S;
    cout << S.isValid(word) << endl;
    return 0;
}