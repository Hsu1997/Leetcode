#include <iostream>

using namespace std;

class Solution {
public:
    int countOrders(int n) {
        long long int ans = 1;
        for (int i = 1; i <= n; i++){
            ans *= i;
            ans *= (2 * i - 1);
            ans %= 1000000007;
        }
        return ans;
    };
};

int main(){
    int n = 3;
    Solution S;
    cout << S.countOrders(n) << endl;
}