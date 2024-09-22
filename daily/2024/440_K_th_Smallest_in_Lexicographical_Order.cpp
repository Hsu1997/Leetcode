#include <iostream>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int step = countSteps(n, curr);
            // cout << "curr = " << curr << ", step = " << step << ", k = " << k << endl;
            if (step < k) {
                curr++;
                k -= step;
            }
            else {
                curr *= 10;
            }
            k--;
        }
        return curr;
    }

private:
    int countSteps(int n, long curr) {
        int steps = 0;
        long curr_step = 10;
        curr *= 10;
        while(curr <= n){
            steps += min(curr_step, n - curr + 1);
            curr_step *= 10;
            curr *= 10;
        }
        return steps;
    }
};

int main(){
    int n = 13;
    int k = 2;
    // int n = 1;
    // int k = 1;
    // int n = 2;
    // int k = 2;
    // int n = 681692778;
    // int k = 351251360;
    Solution S;
    cout << S.findKthNumber(n, k) << endl;
    return 0;
}