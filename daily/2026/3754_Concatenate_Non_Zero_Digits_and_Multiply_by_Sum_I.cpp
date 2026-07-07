#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        long long x = 0;
        long long sum = 0;
        long long d = 1;
        while(n){
            int curr = n % 10;
            if (curr){
                x += d * curr;
                sum += curr;
                d *= 10;
            }
            n /= 10;
        }
        return x * sum;
    }
};

int main(){
    int n = 10203004;
    // int n = 1000;
    // int n = 29482750;
    // int n = 28400023;
    Solution S;
    cout << S.sumAndMultiply(n) << endl;
    return 0;
}