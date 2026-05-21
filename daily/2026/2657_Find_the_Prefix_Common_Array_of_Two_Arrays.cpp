#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);
        vector<int> cnt(n + 1, 0);
        int c = 0;
        for (int i = 0; i < n; i++){
            cnt[A[i]]++;
            if (cnt[A[i]] == 2) c++;
            cnt[B[i]]++;
            if (cnt[B[i]] == 2) c++;
            ans[i] = c;
        }
        return ans;
    }
};

int main(){
    vector<int> A = {1,3,2,4};
    vector<int> B = {3,1,2,4};
    // vector<int> A = {2,3,1};
    // vector<int> B = {3,1,2};
    Solution S;
    vector<int> ans = S.findThePrefixCommonArray(A, B);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}