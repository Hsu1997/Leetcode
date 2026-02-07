#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        // use stack to count 'ba' pair appeared times
        int cntb = 0;
        int ans = 0;
        for (char c : s){
            if (c == 'a'){
                if (cntb > 0) cntb--, ans++;
            }
            else cntb++;
        }
        return ans;
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