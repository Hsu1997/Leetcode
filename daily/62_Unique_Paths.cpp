#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        double ans = 1;
        int sum = m + n - 2;
        for (int i = 1; i <= m - 1; i++){
            ans = ans * (sum-(m-1)+i) / i;
        }
        return ans;
    }
};

int main(){
    int m = 7;
    int n = 3;
    Solution S;
    cout << S.uniquePaths(m, n) << endl;
    return 0;
}