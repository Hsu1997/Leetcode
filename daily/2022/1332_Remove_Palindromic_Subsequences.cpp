#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i < j){
            if (s[i++] != s[j--]) return 2;
        }
        return 1;
    }
};

int main(){
    string s = "abba";
    Solution S;
    cout << S.removePalindromeSub(s) << endl;
    return 0;
}