#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0;
        int r = 0;
        int u = 0;
        for (char c : moves){
            l += c == 'L';
            r += c == 'R';
            u += c == '_';
        }
        return u + abs(l - r);
    }
};

int main(){
    string moves = "L_RL__R";
    // string moves = "_R__LL_";
    // string moves = "_______";
    Solution S;
    cout << S.furthestDistanceFromOrigin(moves) << endl;
    return 0;
}