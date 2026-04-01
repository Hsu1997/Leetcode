#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        string ans(n + m - 1, 'a');
        vector<bool> fixed(n + m - 1, false);
        for (int i = 0; i < n; i++){
            if (str1[i] == 'T'){
                for (int j = 0; j < m; j++){
                    if (fixed[i + j] && ans[i + j] != str2[j]) return "";
                    ans[i + j] = str2[j];
                    fixed[i + j] = true;
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (str1[i] == 'F'){
                bool different = false;
                int lastest = -1;
                for (int j = i + m - 1; j >= i; j--){
                    if (ans[j] != str2[j - i]) different = true;
                    if (lastest == -1 && !fixed[j]) lastest = j;
                }
                if (different) continue;
                if (lastest == -1) return "";
                ans[lastest] = 'b';
            }
        }
        return ans;
    }
};

int main(){
    string str1 = "TFTF";
    string str2 = "ab";
    // string str1 = "TFTF";
    // string str2 = "abc";
    // string str1 = "F";
    // string str2 = "d";
    Solution S;
    cout << S.generateString(str1, str2) << endl;
    return 0;
}