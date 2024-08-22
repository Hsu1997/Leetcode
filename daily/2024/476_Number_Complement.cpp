#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask ^ num;
    }
};

int main(){
    int num = 5;
    // int num = 1;
    // int num = 2147483647;
    Solution S;
    cout << S.findComplement(num) << endl;
    return 0;
}