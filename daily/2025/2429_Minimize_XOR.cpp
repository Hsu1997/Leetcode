#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bit = 0;
        int zero = 0;
        int one = 0;
        while((num1 >> bit) || (num2 >> bit)){
            if ((num2 >> bit) & 1) one++;
            else zero++;
            bit++;
        }
        // cout << "0 : " << zero << ", 1 : " << one << endl;
        int ans = 0;
        bit--;
        while(zero && one){
            if (num1 >> bit & 1){
                ans |= (1 << bit);
                one--;
                // cout << "1";
            }
            else{
                zero--;
                // cout << "0";
            }
            bit--;
        }
        // cout << endl << "0 : " << zero << ", 1 : " << one << endl;
        while(one > 0 && bit >= 0){
            ans |= (1 << bit--);
            one--;
        }
        return ans;
    }
};

int main(){
    int num1 = 3;
    int num2 = 5;
    // int num1 = 1;
    // int num2 = 12;
    // int num1 = 23849102;
    // int num2 = 385282;
    Solution S;
    cout << S.minimizeXor(num1, num2) << endl;
    return 0;
}