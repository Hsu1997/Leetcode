#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if (n1 > n2) return false;
        unordered_map<char,int> count;
        for (char c : s1) count[c]++;
        int match = count.size();
        for (int i = 0; i < n1; i++){
            count[s2[i]]--;
            if (count[s2[i]] == 0) match--;
        }
        if (match == 0) return true;
        for (int i = n1; i < n2; i++){
            char add = s2[i];
            char del = s2[i - n1];
            count[add]--;
            if (count[add] == 0) match--;
            count[del]++;
            if (count[del] == 1) match++;
            if (match == 0) return true;
        }
        return false;
    }
};

int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";
    // string s1 = "ab";
    // string s2 = "eidboaoo";
    Solution S;
    cout << S.checkInclusion(s1, s2) << endl;
    return 0;
}