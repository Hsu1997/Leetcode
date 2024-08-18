#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        queue<long long> two;
        queue<long long> three;
        queue<long long> five;
        two.push(2);
        three.push(3);
        five.push(5);
        for (int i = 2; i < n; i++){
            long long temp = min({two.front(), three.front(), five.front()});
            if (two.front() == temp) two.pop();
            if (three.front() == temp) three.pop();
            if (five.front() == temp) five.pop();
            two.push(temp * 2);
            three.push(temp * 3);
            five.push(temp * 5);
        }
        return min({two.front(), three.front(), five.front()});
    }
};

int main(){
    // int n = 10;
    // int n = 1;
    int n = 1680;
    Solution S;
    cout << S.nthUglyNumber(n) << endl;
    return 0;
}