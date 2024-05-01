#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> count(26, 0);
        for (auto i : s) count[i - 'a']++;
        for (auto i : t){
            count[i - 'a']--;
            if (count[i - 'a'] < 0) return false;
        }
        return true;
    }
};

int main(){
    string s = "anagram";
    string t = "nagaram";
    Solution S;
    cout << S.isAnagram(s, t) << endl;
    return 0;
}