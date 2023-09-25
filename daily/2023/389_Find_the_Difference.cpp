#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> count(26);
        for (char i : s) count[i-'a']++;
        for (char i : t) count[i-'a']--;
        for (int i = 0; i < 26; i++) if (count[i] == -1) return ('a'+i);
        return '0';
    }
};

int main(){
    string s = "abcd";
    string t = "abcde";
    Solution S;
    cout << S.findTheDifference(s,t) << endl;
    return 0;
}