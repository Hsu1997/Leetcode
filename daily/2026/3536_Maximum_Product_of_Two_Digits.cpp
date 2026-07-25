#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int v1 = -1;
        int v2 = -1;
        while(n){
            int curr = n % 10;
            v2 = max(min(v1, curr), v2);
            v1 = max(v1, curr);
            n /= 10;
        }
        return v1 * v2;
    }
};

int main(){
    int n = 31;
    // int n = 22;
    // int n = 124;
    Solution S;
    cout << S.maxProduct(n) << endl;
    return 0;
}