#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num * 9 < sum) return "";
        string ans;
        while(sum){
            int curr = min(9, sum);
            sum -= curr;
            ans += '0' + curr;
        }
        ans += string(num - ans.length(), '0');
        return ans;
    }
};

int main(){
    int num = 2;
    int sum = 3;
    // int num = 2;
    // int sum = 17;
    // int num = 1;
    // int sum = 10;
    Solution S;
    cout << S.maxSumOfSquares(num, sum) << endl;
    return 0;
}