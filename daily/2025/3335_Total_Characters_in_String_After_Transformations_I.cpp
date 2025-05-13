#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9 + 7;
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;
        int z_pos = 25;
        for (int i = 0; i < t; i++){
            count[(z_pos + 1) % 26] = (count[(z_pos + 1) % 26] + count[z_pos]) % mod;
            z_pos = (z_pos + 25) % 26;
        }
        int ans = 0;
        for (int i : count) ans = (ans + i) % mod;
        return ans;
    }
};

int main(){
    string s = "abcyy";
    int t = 2;
    // string s = "azbk";
    // int t = 1;
    // string s = "jqktcurgdvlibczdsvnsg";
    // int t = 7517;
    Solution S;
    cout << S.lengthAfterTransformations(s, t) << endl;
    return 0;
}