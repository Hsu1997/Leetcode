#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        int k, l;
        int erase = 0;
        while(i < j){
            if (s[i] == s[j]){
                i++;
                j--;
            }
            else if (erase == 0){
                erase++;
                k = i++;
                l = j-1;
            }
            else{
                break;
            }
        }
        if (i >= j) return true;
        while(k < l){
            if (s[k] == s[l]){
                k++;
                l--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

int main(){
    string s = "abcccccba";
    Solution S;
    cout << S.validPalindrome(s) << endl;
    return 0;
}