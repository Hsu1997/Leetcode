#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> ans;
    void helper(int i, int n){
        if (i > n) return;
        ans.push_back(i);
        for (int j = 0; j <= 9; j++){
            helper(i * 10 + j, n);
        }
        return;
    }
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; i++) helper(i, n);
        return ans;
    }
};

int main(){
    int n = 13;
    // int n = 2;
    // int n = 50000;
    Solution S;
    vector<int> ans = S.lexicalOrder(n);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}