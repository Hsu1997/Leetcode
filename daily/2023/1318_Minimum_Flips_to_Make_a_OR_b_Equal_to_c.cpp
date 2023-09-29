#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(a > 0 || b > 0 || c > 0){
            if (c % 2){
                if (a % 2 == 0 && b % 2 == 0) ans++;
            }
            else ans += (a % 2 == 1) + (b % 2 == 1);
            c /= 2, b /= 2, a /= 2;
        }
        return ans;
    }
};

int main(){
    // int a = 2;
    // int b = 6;
    // int c = 5;
    // int a = 4;
    // int b = 2;
    // int c = 7;
    // int a = 1;
    // int b = 2;
    // int c = 3;
    int a = 8;
    int b = 3;
    int c = 5;
    Solution S;
    cout << S.minFlips(a,b,c) << endl;
    return 0;
}