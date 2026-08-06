#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mul(int n){
        int res = 1;
        while (n){
            res *= n % 10;
            n /= 10;
        }
        return res;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if (mul(n) % t == 0) return n;
            n++;
        }
        return -1;
    }
};

int main(){
    int n = 10;
    int t = 2;
    // int n = 15;
    // int t = 3;
    Solution S;
    cout << S.smallestNumber(n, t) << endl;
    return 0;
}