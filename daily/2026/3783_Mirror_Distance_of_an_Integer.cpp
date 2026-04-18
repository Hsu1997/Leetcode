#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        int x = n;
        int y = 0;
        while(n){
            y = y * 10 + (n % 10);
            n /= 10;
        }
        return abs(x - y);
    }
};

int main(){
    int n = 25;
    // int n = 10;
    // int n = 7;
    Solution S;
    cout << S.mirrorDistance(n) << endl;
    return 0;
}