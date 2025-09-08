#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasZero(int x){
        while(x){
            if (x % 10 == 0) return true;
            x /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++){
            int j = n - i;
            if (!hasZero(i) && !hasZero(j)) return {i, j};
        }
        return {-1, -1};
    }
};

int main(){
    int n = 2;
    // int n = 11;
    // int n = 1010;
    Solution S;
    vector<int> ans = S.getNoZeroIntegers(n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}