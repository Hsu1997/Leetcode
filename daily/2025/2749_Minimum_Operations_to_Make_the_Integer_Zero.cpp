#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long n1 = num1;
        long long n2 = num2;
        int round = 1;
        n1 -= n2;
        while(n1 >= round){
            if (__builtin_popcountll(n1) <= round) return round;
            n1 -= n2;
            round++;
        }
        return -1;
    }
};

int main(){
    int num1 = 3;
    int num2 = -2;
    // int num1 = 5;
    // int num2 = 7;
    // int num1 = 110;
    // int num2 = 55;
    // int num1 = 112577768;
    // int num2 = -501662198;
    Solution S;
    cout << S.makeTheIntegerZero(num1, num2) << endl;
    return 0;
}