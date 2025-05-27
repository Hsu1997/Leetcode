#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        // [1 2 3 ... (m-1) -m] + ..... + [(n/m-1)*m+1 .... -(n / m * m)] + [.... n]
        // [1 2 .... n] - 2 * [m 2*m .... n/m*m]
        // (1 + ... + n) - 2 * m(1 + ... + group)
        int group = n / m;
        return (1 + n) * n / 2 - (1 + group) * group * m;
    }
};

int main(){
    int n = 10;
    int m = 3;
    // int n = 5;
    // int m = 6;
    // int n = 5;
    // int m = 1;
    Solution S;
    cout << S.differenceOfSums(n, m) << endl;
    return 0;
}