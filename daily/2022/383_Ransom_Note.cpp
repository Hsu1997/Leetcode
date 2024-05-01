#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26,0);
        for (auto i : magazine) count[i-'a']++;
        for (auto i : ransomNote){
            if (count[i-'a'] < 1) return false;
            count[i-'a']--;
        }
        return true;
    }
};

int main(){
    string ransomNote = "a";
    string magazine = "b";
    Solution S;
    cout << S.canConstruct(ransomNote, magazine) << endl;
    return 0;
}