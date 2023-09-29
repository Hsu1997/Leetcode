#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int s = min(word1.length(), word2.length());
        string ans;
        for (int i = 0; i < s; i++){
            ans += word1[i];
            ans += word2[i];
        }
        ans += word1.substr(s);
        ans += word2.substr(s);
        return ans;
    }
};

int main(){
    // string word1 = "abc";
    // string word2 = "pqr";
    string word1 = "ab";
    string word2 = "pqrs";
    Solution S;
    cout << S.mergeAlternately(word1, word2) << endl;
    return 0;
}