#include <iostream>

using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        int div = 1000;
        while(div > 0){
            if (temp / div == 6){
                num += 3 * div;
                return num;
            };
            if (temp / div != 0) temp -= 9 * div;
            div /= 10;
        }
        return num;
    }
};

int main(){
    // int num = 9669;
    int num = 696;
    Solution S;
    cout << S.maximum69Number(num) << endl;
    return 0;
}