#include <iostream>

using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        int divisor = 1000;
        while(divisor){
            if ((num / divisor) % 10 == 6) return num + 3 * divisor;
            divisor /= 10;
        }
        return num;
    }
};

int main(){
    int num = 9669;
    // int num = 9996;
    // int num = 9999;
    Solution S;
    cout << S.maximum69Number(num) << endl;
    return 0;
}