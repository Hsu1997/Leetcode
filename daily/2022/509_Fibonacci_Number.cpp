#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int l2 = 0;
        int l1 = 1;
        for (int i = 2; i < n; i++){
            int temp = l2 + l1;
            l2 = l1;
            l1 = temp;
        }
        return l2 + l1;
    }
};

int main(){
    int n = 7;
    Solution S;
    cout << S.fib(n) << endl;
    return 0;
}