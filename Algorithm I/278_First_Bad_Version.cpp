#include <iostream>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int n, bad;
    // find the first ture 
    int firstBadVersion(int n) {
        if (n == 1) return 1;
        // a : last false 
        // b : first true
        int a = 1;
        int b = n;
        // for all true
        if (isBadVersion(a)) return 1;
        while( b - a > 1){
            if (isBadVersion( a + (b-a)/2 )){
                b = a + (b-a)/2;
            }
            else a = a + (b-a)/2;
        }
        return b;
    }
private:
    bool isBadVersion(int version);
};

bool Solution::isBadVersion(int version){
    if (version < bad) return false;
    else return true;
}

int main(){
    Solution sol;
    cin >> sol.n >> sol.bad;
    cout << sol.firstBadVersion(sol.n) << endl;
}