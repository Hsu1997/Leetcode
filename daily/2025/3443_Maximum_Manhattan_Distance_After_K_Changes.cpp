#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int l = 0;
        int r = 0;
        int u = 0;
        int d = 0;
        for (char c : s){
            u += (c == 'N');
            d += (c == 'S');
            r += (c == 'E');
            l += (c == 'W');
            ans = max(ans, abs(u-d) + abs(r-l) + 2 * min(k, min(l, r) + min(u, d)));
        }
        return ans;
    }
};

int main(){
    string s = "NWSE";
    int k = 1;
    // string s = "NSWWEW";
    // int k = 3;
    Solution S;
    cout << S.maxDistance(s, k) << endl;
    return 0;
}