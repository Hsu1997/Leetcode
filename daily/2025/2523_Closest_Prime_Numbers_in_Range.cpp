#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPrime(int num){
        int i = 2;
        while(i * i <= num){
            if (num % i == 0) return false;
            i++;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans = {-1, -1};
        int diff = INT_MAX;
        int prev = 0;
        for (int curr = max(2, left); curr <= right; curr++){
            if (isPrime(curr)){
                if (prev && curr - prev < diff){
                    diff = curr - prev;
                    ans = {prev, curr};
                }
                prev = curr;
            }
        }
        return ans;
    }
};

int main(){
    int left = 10;
    int right = 19;
    // int left = 4;
    // int right = 6;
    Solution S;
    vector<int> ans = S.closestPrimes(left, right);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}