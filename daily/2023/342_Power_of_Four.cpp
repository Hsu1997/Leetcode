#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while(n > 1){
            if (n & 1 || n & 2) return false;
            else n /= 4;
        }
        return true;
    }
};

int main(){
    int n = 16;
    Solution S;
    cout << S.isPowerOfFour(n) << endl;
    return 0;
}