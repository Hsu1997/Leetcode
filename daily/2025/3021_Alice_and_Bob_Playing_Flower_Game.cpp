#include <iostream>

using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        return (long long)n * m / 2;
    }
};

int main(){
    int n = 3;
    int m = 2;
    // int n = 1;
    // int m = 1;
    Solution S;
    cout << S.flowerGame(n, m) << endl;
    return 0;
}