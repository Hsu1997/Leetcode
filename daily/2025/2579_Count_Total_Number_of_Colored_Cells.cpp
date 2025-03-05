#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long coloredCells(int n) {

        return (long long)n * n * 2 - 2 * n + 1;
    }
};

int main(){
    int n = 1;
    // int n = 2;
    // int n = 3;
    // int n = 100000;
    Solution S;
    cout << S.coloredCells(n) << endl;
    return 0;
}