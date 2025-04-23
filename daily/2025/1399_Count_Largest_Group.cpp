#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int sumOfDigits(int n){
        int ans = 0;
        while(n){
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> m;
        for (int i = 1; i <= n; i++){
            m[sumOfDigits(i)]++;
        }
        int ans = 0;
        int c = 0;
        for (auto& [sum, count] : m){
            if (count > c){
                c = count;
                ans = 1;
            }
            else if (count == c) ans++;
            else continue;
        }
        return ans;
    }
};

int main(){
    int n = 13;
    // int n = 2;
    Solution S;
    cout << S.countLargestGroup(n) << endl;
    return 0;
}