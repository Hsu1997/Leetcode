#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        int k = 0;
        for (int i = 0; i < n1; i++){
            if (str1[i] == str2[k]) k++;
            else if (str1[i] == 'z' && str2[k] == 'a' || str1[i]+1 == str2[k]) k++;
            else continue;
            if (k == n2) return true;
        }
        return false;
    }
};

int main(){
    string str1 = "abc";
    string str2 = "ad";
    // string str1 = "zc";
    // string str2 = "ad";
    // string str1 = "ab";
    // string str2 = "d";
    // string str1 = "pc";
    // string str2 = "qc";
    Solution S;
    cout << S.canMakeSubsequence(str1, str2) << endl;
    return 0;
}