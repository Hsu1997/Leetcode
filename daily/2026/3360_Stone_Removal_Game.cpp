#include <iostream>

using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        bool ans = false;
        int token = 10;
        n -= token;
        while(n >= 0){
            token--;
            n -= token;
            ans = !ans;
        }
        return ans;
    }
};

int main(){
    int n = 12;
    // int n = 1;
    // int n = 38;
    // int n = 50;
    // int n = 19;
    // int n = 27;
    Solution S;
    cout << S.canAliceWin(n) << endl;
    return 0;
}