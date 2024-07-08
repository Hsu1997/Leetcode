#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> c(n, 1);
        int start = 0;
        for (int d = 0; d < n-1; d++){
            // cout << "round " << d+1 << " : " ;
            // for (auto j : c) cout << j << " ";
            // cout << endl;
            int count = 0;
            while(count < k){
                if (c[start] == 1) count++;
                start++;
                start %= n;
            }
            c[(start + n - 1) % n] = -1;
        }
        for (int i = 0; i < n; i++) if (c[i] == 1) return i+1;
        return -1;
    }
};

// Better
// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         return helper(n, k) + 1;
//     }
//     int helper(int n, int k){
//         if (n == 1) return 0;
//         return (helper(n-1, k) + k) % n;
//     }
// };

// Best
// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         int ans = 0;
//         for (int i = 2; i <= n; i++){
//             ans = (ans + k) % i;
//         }
//         return ans+1;
//     }
// };

int main(){
    int n = 5;
    int k = 2;
    // int n = 6;
    // int k = 5;
    Solution S;
    cout << S.findTheWinner(n, k) << endl;
    return 0;
}