#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        while(n > 1){
            if (n % 3) return false;
            n /= 3;
        }
        return true;
    }
};

int main(){
    int n = 27;
    // int n = 0;
    // int n = -1;
    Solution S;
    cout << S.isPowerOfThree(n) << endl;
    return 0;
}