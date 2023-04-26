#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int helper(int num){
        int ans = 0;
        while(num){
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }

    int addDigits(int num) {
        while(num > 9){
            num = helper(num);
        }
        return num;
    }
};

int main(){
    // int num = 38;
    int num = 0;
    Solution S;
    cout << S.addDigits(num) << endl;
    return 0;
}