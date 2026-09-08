#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countCommas(int n) {
        return max(0, n - 999);
    }
};

int main(){
    int n = 1002;
    // int n = 998;
    Solution S;
    cout << S.countCommas(n) << endl;
    return 0;
}