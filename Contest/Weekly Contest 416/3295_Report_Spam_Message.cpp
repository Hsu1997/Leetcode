#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> ban;
        for (string s : bannedWords) ban.insert(s);
        int count = 0;
        for (string s : message){
            if (ban.find(s) != ban.end()) count++;
            if (count >= 2) return true;
        }
        return false;
    }
};

int main(){
    vector<string> message = {"hello","world","leetcode"};
    vector<string> bannedWords = {"world","hello"};
    // vector<string> message = {"hello","programming","fun"};
    // vector<string>  bannedWords = {"world","programming","leetcode"};
    Solution S;
    cout << S.reportSpam(message, bannedWords) << endl;
    return 0;
}