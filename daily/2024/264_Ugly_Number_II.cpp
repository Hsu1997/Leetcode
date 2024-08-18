#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        priority_queue<long long, vector<long long>, greater<long long>> two;
        priority_queue<long long, vector<long long>, greater<long long>> three;
        priority_queue<long long, vector<long long>, greater<long long>> five;
        two.push(2);
        three.push(3);
        five.push(5);
        for (int i = 2; i < n; i++){
            long long temp = min({two.top(), three.top(), five.top()});
            if (two.top() == temp) two.pop();
            if (three.top() == temp) three.pop();
            if (five.top() == temp) five.pop();
            two.push(temp * 2);
            three.push(temp * 3);
            five.push(temp * 5);
        }
        return min({two.top(), three.top(), five.top()});
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