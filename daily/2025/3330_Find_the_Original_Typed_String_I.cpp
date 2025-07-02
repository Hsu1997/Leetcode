#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int ans = 1;
        for (int i = 1; i < n; i++) if (word[i] == word[i-1]) ans++;
        return ans;
    }
};

int main(){
    string word = "abbcccc";
    // string word = "abcd";
    // string word = "aaaa";
    Solution S;
    cout << S.possibleStringCount(word) << endl;
    return 0;
}