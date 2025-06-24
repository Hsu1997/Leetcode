#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int num[100];
    bool is_palindrome(long long n, int k){
        int l = 0;
        while(n){
            num[l++] = n % k;
            n /= k;
        }
        l--;
        int i = 0;
        while(i < l){
            if (num[i++] != num[l--]) return false;
        }
        return true;
    }
    long long kMirror(int k, int n) {
        int count = 0;
        long long ans = 0;
        int left = 1;
        for (int i = 1; i < 10; i++){
            if (is_palindrome(i, k)){
                ans += i;
                count++;
                if (count == n) return ans;
            }
        }
        // 10 is not palindrome when base 10
        while(count < n){
            int right = left * 10;
            for (int i = left; i < right; i++){
                long long combined = i;
                int x = i;
                while(x){
                    combined = combined * 10 + (x % 10);
                    x /= 10;
                }
                if (is_palindrome(combined, k)){
                    ans += combined;
                    count++;
                    if (count == n) return ans;
                }
            }
            for (int i = left; i < right; i++){
                for (int j = 0; j < 10; j++){
                    long long combined = i * 10 + j;
                    int x = i;
                    while(x){
                        combined = combined * 10 + (x % 10);
                        x /= 10;
                    }
                    if (is_palindrome(combined, k)){
                        ans += combined;
                        count++;
                        if (count == n) return ans;
                    }
                }
            }
            left *= 10;
        }
        return ans;
    }
};

int main(){
    int k = 2;
    int n = 5;
    // int k = 3;
    // int n = 7;
    // int k = 7;
    // int n = 17;
    Solution S;
    cout << S.kMirror(k, n) << endl;
    return 0;
}