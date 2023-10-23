#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        int back = 0;
        while(true){
            back = 0;
            while(i >= 0 && (back || s[i] == '#')) back += (s[i--] == '#')? 1 : -1;
            back = 0;
            while(j >= 0 && (back || t[j] == '#')) back += (t[j--] == '#')? 1 : -1;
            if (i >= 0 && j >= 0 && s[i] == t[j]) i--, j--;
            else break;
        }
        return i == -1 && j == -1;
    }
};

int main(){
    // string s = "ab#c";
    // string t = "ad#c";
    // string s = "ab##";
    // string t = "c#d#";
    // string s = "a#c";
    // string t = "b";
    string s = "bbbextm";
    string t = "bbb#extm";
    Solution S;
    cout << S.backspaceCompare(s, t) << endl;
    return 0;
}