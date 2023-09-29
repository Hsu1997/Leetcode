#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        for (int k = 0; k < m; k++){
            int i = k;
            int j = 0;
            while(i < m && j < n && haystack[i++] == needle[j++]) if (j == n) return k;
        }
        return -1;
    }
};

int main(){
    // string haystack = "sadbutsad";
    // string needle = "sad";
    string haystack = "leetcode";
    string needle = "leeto";
    Solution S;
    cout << S.strStr(haystack, needle) << endl;
    return 0;
}