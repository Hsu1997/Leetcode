#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> cnta(n);
        vector<int> cntb(n);
        cnta[0] = s[0] == 'a';
        for (int i = 1; i < n; i++){
            cnta[i] = cnta[i-1] + (s[i] == 'a');
        }
        cntb[n-1] = s[n-1] == 'b';
        for (int i = n - 2; i >= 0; i--){
            cntb[i] = cntb[i+1] + (s[i] == 'b');
        }
        int ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, cnta[i] + cntb[i]);
        return n - ans;
    }
};

int main(){
    string s = "aababbab";
    // string s = "bbaaaaabb";
    // string s = "ababaaaabbbbbaaababbbbbbaaabbaababbabbbbaabbbbaabbabbabaabbbababaa";
    Solution S;
    cout << S.minimumDeletions(s) << endl;
    return 0;
}