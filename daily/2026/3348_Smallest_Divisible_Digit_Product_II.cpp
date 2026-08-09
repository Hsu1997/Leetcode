#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        for (int i = 2; i < 10; i++){
            while(temp % i == 0) temp /= i;
        }
        if (temp > 1) return "-1";
        int n = num.length();
        vector<long long> remain(n + 1, 0);
        remain[0] = t;
        int pos = n - 1;
        for (int i = 0; i < n; i++){
            int curr = num[i] - '0';
            if (curr == 0){
                pos = i;
                break;
            }
            remain[i + 1] = remain[i] / gcd(remain[i], curr);
        }
        if (remain[n] == 1) return num;
        for (int i = pos; i >= 0; i--){
            while(num[i] + 1 <= '9'){
                num[i] += 1;
                long long currT = remain[i] / gcd(remain[i], num[i] - '0');
                int k = 9;
                for (int j = n - 1; j > i; j--){
                    while(currT % k != 0){
                        k--;
                    }
                    currT /= k;
                    num[j] = k + '0';
                }
                if (currT == 1) return num;
            }
        }
        string ans = "";
        for (int k = 9; k > 1; k--){
            while(t % k == 0){
                ans.push_back(k + '0');
                t /= k;
            }
        }
        ans += string(max(0, n + 1 - (int)ans.length()), '1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    // string num = "1234";
    // long long t = 256;
    // string num = "12355";
    // long long t = 50;
    // string num = "11111";
    // long long t = 26;
    string num = "78";
    long long t = 42;
    Solution S;
    cout << S.smallestNumber(num, t) << endl;
    return 0;
}