#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1;
        string w2;
        for (auto i : word1) w1 += i;
        for (auto i : word2) w2 += i;
        if (w1.compare(w2) == 0) return true;
        return false;
    }
};

int main(){
    // vector<string> word1 = {"ab", "c"};
    // vector<string> word2 = {"a", "bc"};
    vector<string> word1 = {"a", "cb"};
    vector<string> word2 = {"ab", "c"};
    // vector<string> word1 = {"abc", "d", "defg"};
    // vector<string> word2 = {"abcddefg"};
    Solution S;
    cout << S.arrayStringsAreEqual(word1, word2) << endl;
    return 0;
}