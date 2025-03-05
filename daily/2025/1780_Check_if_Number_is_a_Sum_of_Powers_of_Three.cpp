#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int power = 0;
        int curr = 1;
        while(n > curr){
            curr *= 3;
            power++;
        }
        while(power >= 0){
            if (n >= curr) n -= curr;
            curr /= 3;
            power--;
        }
        return n == 0;
    }
};

int main(){
    int n = 12;
    // int n = 91;
    // int n = 21;
    Solution S;
    cout << S.checkPowersOfThree(n) << endl;
    return 0;
}