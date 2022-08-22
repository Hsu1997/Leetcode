#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        while(n > 1){
            if (((n & 1) || (n & 2)) == 0) n /= 4;
            else return false;
        }

        return true;
    }
};

int main(){
    int n = 16;
    Solution S;
    cout << S.isPowerOfFour(n) << endl;
    // for (int i = 0; i < 66; i++) cout << "i = " << i << " : " << S.isPowerOfFour(i) << endl;
    return 0;
}