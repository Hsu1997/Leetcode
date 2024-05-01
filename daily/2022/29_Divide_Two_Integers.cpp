#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        int signal = (dividend > 0 ^ divisor > 0)? -1:1;
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        long ans = 0;
        // cout << dvd << " " << dvs << " " << ans << " " << signal << endl;
        while(dvs <= dvd){
            long temp = dvs;
            long m = 1;
            while(temp << 1 <= dvd){
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return signal * ans;
    }
};

int main(){
    int dividend = -2147483648;
    int divisior = -1;
    Solution S;
    cout << S.divide(dividend, divisior) << endl;
    return 0;
}