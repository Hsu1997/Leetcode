#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        int change = 0;
        for (int i = n; i >= 2; i--){
            int mid = 1 << (i-1);
            if (k > mid){
                change++;
                k = mid - (k - mid);
            }
            else if (k == mid) return (change % 2 == 0)? '1' : '0';
            else continue;
        }
        if (k != 1) return '#';
        return (change % 2 == 0)? '0' : '1';
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
    Solution S;
    cout << S.findKthBit(n, k) << endl;
    return 0;
}