#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans = 0;
        for (int k = 0; k < 4; k++){
            ans += pow(10, k) * min({num1%10, num2%10, num3%10});
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        return ans;
    }
};

int main(){
    int num1 = 1;
    int num2 = 10;
    int num3 = 100;
    // int num1 = 987;
    // int num2 = 879;
    // int num3 = 798;
    // int num1 = 1;
    // int num2 = 2;
    // int num3 = 3;
    Solution S;
    cout << S.generateKey(num1, num2, num3) << endl;
    return 0;
}