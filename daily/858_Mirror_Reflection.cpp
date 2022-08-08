#include <iostream>

using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int pc = p;
        int qc = q;
        if (qc > pc) swap(pc, qc);
        while(qc){
            pc %= qc;
            swap(pc, qc);
        }

        int product = p * q;
        int gcd = pc;
        int lcm = product / gcd;
        int m = lcm / p;
        int n = lcm / q;
        // cout << m << ", " << n << endl;

        if (m % 2 == 1){
            if (n % 2 == 1) return 1;
            else return 2;
        }
        else{
            if (n % 2 == 0) return -1;
            else return 0;
        }
    }
};

int main(){
    int p = 3;
    int q = 1;
    Solution S;
    cout << S.mirrorReflection(p, q) << endl;
    return 0;
}