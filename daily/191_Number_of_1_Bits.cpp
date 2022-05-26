#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int onebit = 0;
        while(n > 0){
            if (n % 2 == 1) onebit++;
            n /= 2;
        }
        return onebit;
    }
};

int main(){
    uint32_t n = 00000000000000000000000000001011;
    Solution S;
    cout << S.hammingWeight(n) << endl;
    return 0;
}