#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        vector<int> counter(26, 0);
        for (char c : s) counter[c-'a']++;
        for (int i = 0; i < 26; i++){
            for (int j = 0; j < 26; j++){
                if (i != j && counter[i] && counter[j]){
                    int xcount = 0;
                    int ycount = 0;
                    int rest_y = counter[j];
                    for (char c : s){
                        if (c == 'a' + i) xcount++;
                        if (c == 'a' + j) ycount++, rest_y--;
                        if (ycount) ans = max(ans, xcount - ycount);
                        if (ycount > xcount && rest_y) xcount = 0, ycount = 0;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    string s = "aababbb";
    // string s = "abcde";
    Solution S;
    cout <<S.largestVariance(s) << endl;
    return 0;
}