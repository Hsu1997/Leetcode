#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        int cntOdd[26] = {0};
        int cntEven[26] = {0};
        for (int i = 0; i < n; i++){
            if (i % 2 == 0){
                cntEven[s1[i] - 'a']++;
                cntEven[s2[i] - 'a']--;
            }
            else{
                cntOdd[s1[i] - 'a']++;
                cntOdd[s2[i] - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++) if (cntOdd[i] != 0 || cntEven[i] != 0) return false;
        return true;
    }
};

int main(){
    string s1 = "abcdba";
    string s2 = "cabdab";
    // string s1 = "abe";
    // string s2 = "bea";
    Solution S;
    cout << S.checkStrings(s1, s2) << endl;
    return 0;
}