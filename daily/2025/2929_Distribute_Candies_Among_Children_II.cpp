#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long cal(int i){
        if (i < 0) return 0;
        return 1LL * i * (i - 1) / 2;
    }
    long long distributeCandies(int n, int limit) {
        return cal(n + 2) - 3 * cal(n - (limit + 1) + 2) + 3 * cal(n - 2 * (limit + 1) + 2) - cal(n - 3 * (limit + 1) + 2);
    }
};

int main(){
    int n = 5;
    int limit = 2;
    // int n = 3;
    // int limit = 3;
    // int n = 1;
    // int limit = 3;
    Solution S;
    cout << S.distributeCandies(n, limit) << endl;
    return 0;
}