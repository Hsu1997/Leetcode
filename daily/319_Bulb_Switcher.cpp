#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

int main(){
    int n = 3;
    Solution S;
    cout << S.bulbSwitch(n) << endl;
    return 0;
}