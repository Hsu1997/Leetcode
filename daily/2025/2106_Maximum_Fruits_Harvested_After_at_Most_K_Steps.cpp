#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = 0;
        int n = fruits.size();
        int start = 0;
        while(start < n && fruits[start][0] < startPos - k) start++;
        int end = start;
        int curr_acc = 0;
        while(start < n && fruits[start][0] < startPos){
            int left = startPos - fruits[start][0];
            int right = 0;
            if (left <= k / 3) right = startPos + (k - 2 * left);
            else right = startPos + (k - left) / 2;
            while(end < n && fruits[end][0] <= right){
                curr_acc += fruits[end][1];
                end++;
            }
            ans = max(ans, curr_acc);
            curr_acc -= fruits[start][1];
            start++;
        }
        while(end < n && fruits[end][0] - k <= startPos) curr_acc += fruits[end++][1];
        ans = max(ans, curr_acc);
        return ans;
    }
};

int main(){
    vector<vector<int>> fruits = {{2,8},{6,3},{8,6}};
    int startPos = 5;
    int k = 4;
    // vector<vector<int>> fruits = {{0,9},{4,1},{5,7},{6,2},{7,4},{10,9}};
    // int startPos = 5;
    // int k = 4;
    // vector<vector<int>> fruits = {{0,3},{6,4},{8,5}};
    // int startPos = 3;
    // int k = 2;
    // vector<vector<int>> fruits = {{0,10000}};
    // int startPos = 200000;
    // int k = 200000;
    Solution S;
    cout << S.maxTotalFruits(fruits, startPos, k) << endl;
    return 0;
}