#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26);
        for (auto i : s) count[i-'a']++;
        for (int i = 0; i < s.length(); i++) if (count[s[i]-'a'] == 1) return i;
        return -1;
    }
};

int main(){
    // string s = "leetcode";
    // string s = "loveleetcode";
    string s = "aabb";
    Solution S;
    cout << S.firstUniqChar(s) << endl;
    return 0;
}