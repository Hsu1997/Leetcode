#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n > 1){
            if (n % 2) return false;
            n /= 2;
        }
        return (n == 1);
    }
};

int main(){
    int n = 1;
    // int n = 16;
    // int n = 3;
    // int n = 0;
    // int n = -10000;
    Solution S;
    cout << S.isPowerOfTwo(n) << endl;
    return 0;
}