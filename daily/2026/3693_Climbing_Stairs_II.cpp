#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int a = 0;
        int b = 0;
        int c = 0;
        for (int i = 0; i < n; i++){
            int curr = costs[i] + min({a + 9, b + 4, c + 1});
            a = b;
            b = c;
            c = curr;
        }
        return c;
    }
};

int main(){
    int n = 4;
    vector<int> costs = {1,2,3,4};
    // int n = 4;
    // vector<int> costs = {5,1,6,2};
    // int n = 3;
    // vector<int> costs = {9,8,3};
    Solution S;
    cout << S.climbStairs(n, costs) << endl;
    return 0;
}