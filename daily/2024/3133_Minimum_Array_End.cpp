#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        n--;
        for (long long mask = 1; n > 0; mask <<= 1){
            if ((ans & mask) == 0){
                ans |= (n & 1) * mask;
                n >>= 1;
            }
        }
        return ans;
    }
};

int main(){
    int n = 3;
    int x = 4;
    // int n = 2;
    // int x = 7;
    Solution S;
    cout << S.minEnd(n, x) << endl;
    return 0;
}