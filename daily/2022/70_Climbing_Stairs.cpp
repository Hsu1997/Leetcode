#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 1) return 0;
        if (n <= 3) return n;
        int pre_2 = 2;
        int pre_1 = 3;
        for (int i = 4; i <= n; i++){
            pre_2 += pre_1;
            swap(pre_1,pre_2);
        }
        return pre_1;
    }
};

int main(){
    int n = 3;
    Solution S;
    // for (int i = 2; i < 10; i++) cout << S.climbStairs(i) << endl;
    cout << S.climbStairs(n) << endl;
    return 0;
}