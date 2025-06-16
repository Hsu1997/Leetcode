#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int count(int n, long prefix, long limit){
        int c = 0;
        while(prefix <= n){
            c += min((long)n + 1, limit) - prefix;
            prefix *= 10;
            limit *= 10;
        }
        return c;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while(k){
            int steps = count(n, curr, curr + 1);
            if (k < steps){
                curr *= 10;
                k--;
            }
            else{
                curr++;
                k -= steps;
            }
        }
        return curr;
    }
};

int main(){
    // int n = 13;
    // int k = 2;
    // int n = 1;
    // int k = 1;
    // int n = 2;
    // int k = 2;
    int n = 681692778;
    int k = 351251360;
    Solution S;
    cout << S.findKthNumber(n, k) << endl;
    return 0;
}