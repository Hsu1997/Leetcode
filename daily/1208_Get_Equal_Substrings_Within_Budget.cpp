#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0;
        int j = 0;
        int total = abs(s[0]-t[0]);
        int ans = total <= maxCost;
        while(i < s.length() || j < s.length()){
            if (total <= maxCost){
                if (j < s.length() - 1){
                    j++;
                    total += abs(s[j] - t[j]);
                    if (total <= maxCost) ans = max(ans, j - i + 1);
                }
                else return ans;
            }
            else{
                total -= abs(s[i] - t[i]);
                i++;
                if (i < s.length() && i > j){
                    j = i;
                    total = abs(s[i] - t[i]);
                    ans = max(ans, total <= maxCost? 1 : 0);
                }
            }
            // cout << i << "-" << j << ", total cost = " << total << ", ans =  " << ans << endl;
        }
        return ans;
    }
};

int main(){
    // string s = "abcd";
    // string t = "bcdf";
    // int maxCost = 3;
    string s = "abcd";
    string t = "cdef";
    int maxCost = 1;
    // string s = "abcd";
    // string t = "acde";
    // int maxCost = 0;
    // string s = "fkfnkrfunni";
    // string t = "jyufzxzfbsa";
    // int maxCost = 18;
    // string s = "anryddgaqpjdw";
    // string t = "zjhotgdlmadcf";
    // int maxCost = 5;
    Solution S;
    cout << S.equalSubstring(s,t,maxCost) << endl;
    return 0; 
}