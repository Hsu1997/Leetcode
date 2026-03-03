#include <iostream>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        int invert = 0;
        while(n > 1){
            int mid = 1 << (n - 1);
            if (k == mid) return (invert % 2 == 0)? '1' : '0';
            if (k > mid){
                k = (1 << n) - k;
                invert++;
            }
            n--;
        }
        return (invert % 2 == 1)? '1' : '0';
    }
};

int main(){
    int n = 3;
    int k = 1;
    // int n = 4;
    // int k = 11;
    // int n = 3;
    // int k = 2;
    // int n = 4;
    // int k = 12;
    // int n = 20;
    // int k = 1048575;
    // int n = 20;
    // int k = 529485;
    Solution S;
    cout << S.findKthBit(n, k) << endl;
    return 0;
}