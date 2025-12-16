#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.length();
        int mod = 1e9 + 7;
        int cnt = 0;
        int last = -1;
        long long ans = 1;
        for (int i = 0; i < n; i++){
            if (corridor[i] == 'S'){
                cnt++;
                if (cnt >= 2 && cnt % 2 == 1){
                    ans = (ans * (i - last)) % mod;
                }
                last = i;
            }
        }
        if (cnt == 0 || cnt % 2 == 1) return 0;
        return ans;
    }
};

int main(){
    string corridor = "SSPPSPS";
    // string corridor = "PPSPSP";
    // string corridor = "S";
    // string corridor = "SSPPPPPPPPPPSS";
    Solution S;
    cout << S.numberOfWays(corridor) << endl;
    return 0;
}