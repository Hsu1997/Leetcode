#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> b;
        for (int i : banned) b.insert(i);
        int acc = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++){
            if (acc + i > maxSum) return ans;
            if (b.find(i) == b.end()){
                acc += i;
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> banned = {1,6,5};
    int n = 5;
    int maxSum = 6;
    // vector<int> banned = {1,2,3,4,5,6,7};
    // int n = 8;
    // int maxSum = 1;
    // vector<int> banned = {11};
    // int n = 7;
    // int maxSum = 50;
    Solution S;
    cout << S.maxCount(banned, n, maxSum) << endl;
    return 0;
}