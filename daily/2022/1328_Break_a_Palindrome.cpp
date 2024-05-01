#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if (n == 1) return "";
        int i = 0;
        int j = n-1;
        bool done = 0;
        while(i < j){
            if (palindrome[j] != 'a'){
                palindrome[i] = 'a';
                done = 1;
                break;
            }
            else{
                i++;
                j--;
            }
        }
        if (!done) palindrome[n-1] = 'b';
        
        return palindrome;
    }
};

int main(){
    string palindrome = "abccba";
    Solution S;
    cout << S.breakPalindrome(palindrome) << endl;
    return 0;
}