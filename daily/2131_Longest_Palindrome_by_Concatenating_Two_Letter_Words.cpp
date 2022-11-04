#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> count;
        int ans = 0;
        int rep = 0;
        for (string i : words) count[i]++;
        for (auto i : count){
            // string i = (*it).first;
            string pos = i.first;
            string neg = pos;
            swap(neg[0], neg[1]);
            // cout << pos << " " << neg << " " << count[pos] << " " << count[neg] << " ";
            if (pos.compare(neg) == 0){
                ans += count[pos] / 2;
                count[pos] %= 2;
                if (count[pos] == 1) rep = 1;
            }
            else{
                int m = min(count[pos], count[neg]);
                count[pos] -= m;
                count[neg] -= m;
                ans += m;
            }
            // cout << ans << endl;
        }
        return ans * 4 + rep * 2;
    }
};

int main(){
    Solution S;
    // vector<string> words = {"lc","cl","gg"};
    // vector<string> words = {"ab","ty","yt","lc","cl","ab"};
    // vector<string> words = {"cc","ll","xx"};
    vector<string> words = {"oo","vv","uu","gg","pp","ff","ss","yy","vv","cc","rr","ig","jj","uu","ig","gb","zz","xx","ff","bb","ii","dd","ii","ee","mm","qq","ig","ww","ss","tt","vv","oo","ww","ss","bi","ff","gg","bi","jj","ee","gb","qq","bg","nn","vv","oo","bb","pp","ww","qq","mm","ee","tt","hh","ss","tt","ee","gi","ig","uu","ff","zz","ii","ff","ss","gi","yy","gb","mm","pp","uu","kk","jj","ee"};
    cout << S.longestPalindrome(words) << endl;
    return 0;
}