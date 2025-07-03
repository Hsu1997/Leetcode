#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        int ans = 0;
        k--;
        while(k){
            if (k % 2) ans++;
            k /= 2;
        }
        return 'a' + (ans % 26);
    }
};

int main(){
    int k = 5;
    // int k = 10;
    Solution S;
    cout << S.kthCharacter(k) << endl;
    return 0;
}