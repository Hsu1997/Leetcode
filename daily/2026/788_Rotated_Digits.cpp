#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isGood(int x){
        int original = x;
        int res = 0;
        int p = 1;
        while(x){
            int num = x % 10;
            if (num == 0 || num == 1 || num == 8){
                res += num * p;
            }
            else if (num == 2) res += 5 * p;
            else if (num == 5) res += 2 * p;
            else if (num == 6) res += 9 * p;
            else if (num == 9) res += 6 * p;
            else return false;
            x /= 10;
            p *= 10;
        }
        return original != res;
    }

    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++){
            if (isGood(i)) ans++;
        }
        return ans;
    }
};

int main(){
    int n = 10;
    // int n = 1;
    // int n = 2;
    // int n = 1000;
    Solution S;
    cout << S.rotatedDigits(n) << endl;
    return 0;
}