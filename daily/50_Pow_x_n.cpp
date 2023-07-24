#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return (double)1;
        bool flag = (n < 0)? 1:0;
        double ans = (n % 2)? x:1;
        n /= 2;
        if (flag) n *= -1;
        double temp = myPow(x, n);
        ans *= temp * temp;
        if (flag) ans = 1 / ans;
        return ans;
    }
};

int main(){
    double x = 2;
    int n = 10;
    Solution S;
    cout << S.myPow(x, n) << endl;
    return 0;
}