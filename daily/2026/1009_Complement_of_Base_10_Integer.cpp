#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int l = 0;
        int num = n;
        while(num){
            num >>= 1;
            l++;
        }
        return (1 << l) - 1 - n;
    }
};

int main(){
    int n = 5;
    // int n = 7;
    // int n = 10;
    // int n = 0;
    Solution S;
    cout << S.bitwiseComplement(n) << endl;
    return 0;
}