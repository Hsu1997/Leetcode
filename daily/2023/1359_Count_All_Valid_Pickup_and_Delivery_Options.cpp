#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        long long mod = 1e9+7;
        for (int i = 1; i <= n; i++){
            ans *= (2*i-1);
            ans *= i;
            ans %= mod;
        }
        return ans;
    }
};

int main(){
    int n = 5;
    Solution S;
    cout << S.countOrders(n) << endl;
    return 0;
}