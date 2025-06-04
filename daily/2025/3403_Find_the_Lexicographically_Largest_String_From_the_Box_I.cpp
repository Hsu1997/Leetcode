#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        int n = word.length();
        int len = n - numFriends + 1;
        string ans;
        for (int start = 0; start < n; start++){
            int l = min(len, n - start);
            string temp = word.substr(start, l);
            if (temp > ans) ans = temp;
        }
        return ans;
    }
};

int main(){
    string word = "dbca";
    int numFriends = 2;
    // string word = "gggg";
    // int numFriends = 4;
    // string word = "gh";
    // int numFriends = 1;
    Solution S;
    cout << S.answerString(word, numFriends) << endl;
    return 0;
}