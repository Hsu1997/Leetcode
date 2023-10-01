#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < n){
            while(k < n && s[k] != ' ') k++;
            j = k-1;
            while(i < j) swap(s[i++], s[j--]);
            k++, i = k, j = k;
        }
        return s;
    }
};

int main(){
    string s = "Let's take LeetCode contest";
    // string s = "God Ding";
    Solution S;
    cout << S.reverseWords(s) << endl;
    return 0;
}