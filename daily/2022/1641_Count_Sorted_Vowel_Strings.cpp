#include <iostream>

using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        // a + e + i + o + u = n => H(n,5) => (n+4)! / (n! * 4!)
        return (n+1)*(n+2)*(n+3)*(n+4)/24;
    }
    // int countVowelStrings(int n) {
    //     int a = 1;
    //     int e = 1;
    //     int i = 1;
    //     int o = 1;
    //     int u = 1;
    //     int new_a = 1;
    //     int new_e = 1;
    //     int new_i = 1;
    //     int new_o = 1;
    //     int new_u = 1;
    //     for (int j = 2; j <= n; j++){
    //         new_a = a;
    //         new_e = a + e;
    //         new_i = a + e + i;
    //         new_o = a + e + i + o;
    //         new_u = a + e + i + o + u;
    //         swap(a,new_a);
    //         swap(e,new_e);
    //         swap(i,new_i);
    //         swap(o,new_o);
    //         swap(u,new_u);
    //     }
    //     return a + e + i + o + u;
    // }
};

int main(){
    int n = 33;
    Solution S;
    cout << S.countVowelStrings(n) << endl;
    return 0;
}