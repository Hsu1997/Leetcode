#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        // return __builtin_popcount(k-1) > 0;
        int count = 0;
        k--;
        while(k > 0){
            if (k & 1) count++;
            k /= 2;
        }
        return count % 2 > 0;
    }
};

int main(){
    int n = 1;
    int k = 1;
    // int n = 2;
    // int k = 1;
    // int n = 2;
    // int k = 2;
    Solution S;
    cout << S.kthGrammar(n, k) << endl;
    return 0;
}