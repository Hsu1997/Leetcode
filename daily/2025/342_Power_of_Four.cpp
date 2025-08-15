#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n > 1){
            if (n & 1 || n & 3) return false;
            n >>= 2;
        }
        return n == 1;
    }
};

int main(){
    int n = 16;
    // int n = 5;
    // int n = 1;
    Solution S;
    cout << S.isPowerOfFour(n) << endl;
    return 0;
}