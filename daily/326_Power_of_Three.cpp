#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) return true;
        if (n > 0 && n % 3 == 0) return isPowerOfThree(n/3);
        else return false;
    }
};

int main(){
    int n = 27;
    Solution S;
    cout << S.isPowerOfThree(n) << endl;
    return 0;
}