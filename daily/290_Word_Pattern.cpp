#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ctos;
        unordered_map<string, char> stoc;
        int ptr = 0;
        for (int i = 0; i < pattern.length(); i++){
            if (ptr >= s.length()) return false;
            int start = ptr;
            while(ptr < s.length() && s[ptr] != ' ') ptr++;
            string temps = s.substr(start, ptr - start);
            char tempc = pattern[i];
            ptr++;
            if (ctos.find(tempc) == ctos.end() && stoc.find(temps) == stoc.end()){
                ctos[tempc] = temps;
                stoc[temps] = tempc;
            }
            else if (ctos[tempc] == temps && stoc[temps] == tempc);
            else return false;
            if (i == pattern.length()-1 && ptr < s.length()) return false;
        }

        return true;
    }
};

int main(){
    // string pattern = "abba";
    // string s = "dog cat cat dog";
    // string pattern = "abba";
    // string s = "dog cat cat fish";
    // string pattern = "aaaa";
    // string s = "dog cat cat dog";
    // string pattern = "aaaaa";
    // string s = "aa aa aa aa";
    string pattern = "aaa";
    string s = "aa aa aa aa";
    Solution S;
    cout << S.wordPattern(pattern, s) << endl;
    return 0;
}