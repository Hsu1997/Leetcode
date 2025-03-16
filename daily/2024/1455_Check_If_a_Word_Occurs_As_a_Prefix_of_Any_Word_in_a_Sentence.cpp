#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length();
        int m = searchWord.length();
        int idx = 0;
        int ptr = 0;
        int ans = 0;
        while(idx < n){
            ans++;
            while(sentence[idx] == searchWord[ptr]){
                idx++, ptr++;
                if (ptr == m) return ans;
            }
            ptr = 0;
            while(idx < n && sentence[idx] != ' ') idx++;
            idx++;
        }
        return -1;
    }
};

int main(){
    string sentence = "i love eating burger";
    string searchWord = "burg";
    // string sentence = "this problem is an easy problem";
    // string searchWord = "pro";
    // string sentence = "i am tired";
    // string searchWord = "you";
    Solution S;
    cout << S.isPrefixOfWord(sentence, searchWord) << endl;
    return 0;
}