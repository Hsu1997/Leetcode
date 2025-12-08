#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        unordered_set<int> square;
        for (int i = 1; i <= n; i++) square.insert(i * i);
        for (int a = 1; a <= n; a++){
            for (int b = a + 1; b <= n; b++){
                if (square.find(a * a + b * b) != square.end()) ans++;
            }
        }
        return 2 * ans;
    }
};

int main(){
    int n = 5;
    // int n = 10;
    // int n = 250;
    Solution S;
    cout << S.countTriples(n) << endl;
    return 0;
}