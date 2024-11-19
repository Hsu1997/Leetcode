#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0) return ans;
        bool negative = (k < 0);
        if (k < 0) k = -k;
        int acc = 0;
        for (int i = 0; i < k; i++) acc += code[i];
        for (int i = 0; i < n; i++){
            if (negative) ans[(i+k)%n] = acc;
            else ans[(i-1+n)%n] = acc;
            acc = acc - code[i] + code[(i+k)%n];
        }
        return ans;
    }
};

int main(){
    vector<int> code = {5,7,1,4};
    int k = 3;
    // vector<int> code = {1,2,3,4};
    // int k = 0;
    // vector<int> code = {2,4,9,3};
    // int k = -2;
    Solution S;
    vector<int> ans = S.decrypt(code, k);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}