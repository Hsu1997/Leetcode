#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        time %= (2*n-2);
        if (time < n) return time+1;
        else return 2*n-time-1;
    }
};

int main(){
    int n = 4;
    int time = 5;
    // int n = 3;
    // int time = 2;
    Solution S;
    cout << S.passThePillow(n, time) << endl;
    return 0;
}