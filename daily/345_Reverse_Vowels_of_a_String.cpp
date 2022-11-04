#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length()-1;
        set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};

        while(i < j && i < s.length() && j >= 0){
            while(i < s.length() && vowels.find(s[i]) == vowels.end()) i++;
            while(j >= 0 && vowels.find(s[j]) == vowels.end()) j--;
            if (i < j){
                // cout << i << " " << j << endl;
                swap(s[i], s[j]);
                i++, j--;
            }
        }
        return s;
    }
};

int main(){
    // string s = "hello";
    string s = "leetcode";
    Solution S;
    cout << S.reverseVowels(s) << endl;
    return 0;
}