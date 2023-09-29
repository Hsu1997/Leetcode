#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool test(int val, int index, int n, int maxSum){
        long acc = 0;
        if (val > index) acc += (long)(val + val - index) * (index + 1) / 2;   //[val-index ... val-1 val]
        else acc += (long)(val + 1) * val / 2 + (index + 1 - val); // [1 ... 1 2 3 ... val]
        if (val >= n - index) acc += (long)(val+val-(n-index-1))*(n - index) / 2; // [val val-1 val-2 ... val-(n-index-1)]
        else acc += (long)(val + 1) * val / 2 + (n - index - val) ; // [val val-1 ... 1 1 ... 1]
        return (acc - val <= maxSum);
    }
    int maxValue(int n, int index, int maxSum) {
        int l = 0;
        int r = maxSum;
        while(l < r){
            int mid = l + (r - l + 1) / 2;
            if (test(mid, index, n, maxSum)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};

int main(){
    int n = 4;
    int index = 2;
    int maxSum = 6;
    Solution S;
    cout << S.maxValue(n, index, maxSum) << endl;
    return 0;
}