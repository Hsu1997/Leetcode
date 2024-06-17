#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0;
        int b = sqrt(c);
        while(a <= b){
            if (INT_MAX - b * b < a * a){
                b--;
                continue;
            }
            int temp = a * a + b * b;
            if (temp == c) return true;
            else if (temp < c) a++;
            else b--;
        }
        return false;
    }
};

int main(){
    int c = 5;
    // int c = 3;
    Solution S;
    cout << S.judgeSquareSum(c) << endl;
    return 0;
}