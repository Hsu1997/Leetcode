#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        while (i < s.size()){
            while (j < s.size() && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            j++;
            i = j;
        }
        return s;   
    }
};

int main(){
    string s = "Let's take LeetCode contest";
    Solution S;
    cout << S.reverseWords(s) << endl;
    return 0;
}