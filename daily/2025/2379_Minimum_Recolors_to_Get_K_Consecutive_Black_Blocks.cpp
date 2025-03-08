#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int white = 0;
        for (int i = 0; i < k; i++) if (blocks[i] == 'W') white++;
        int ans = white;
        for (int i = k; i < n; i++){
            white = white - (blocks[i-k] == 'W') + (blocks[i] == 'W');
            ans = min(ans, white);
        }
        return ans;
    }
};

int main(){
    string blocks = "WBBWWBBWBW";
    int k = 7;
    // string blocks = "WBWBBBW";
    // int k = 2;
    Solution S;
    cout << S.minimumRecolors(blocks, k) << endl;
    return 0;
}