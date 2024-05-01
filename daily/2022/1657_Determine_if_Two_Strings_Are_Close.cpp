#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;
        vector<int> c1(26,0);
        vector<int> c2(26,0);
        for (auto i : word1) c1[i-'a']++;
        for (auto i : word2) c2[i-'a']++;
        for (int i = 0; i < 26; i++) if ((c1[i] && !c2[i]) || (!c1[i] && c2[i])) return false;
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        for (int i = 0; i < 26; i++){
            if (c1[i] != c2[i]) return false;
        }
        return true;
    }
};

int main(){
    string word1 = "cabbba";
    string word2 = "abbccc";
    // string word1 = "uau";
    // string word2 = "ssx";
    Solution S;
    cout << S.closeStrings(word1, word2) << endl;
    return 0;
}