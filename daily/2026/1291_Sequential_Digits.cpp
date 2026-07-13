#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int l = to_string(low).length();
        for (int i = l; i < 10; i++){
            int res = 0;
            int add = 0;
            for (int k = 1; k <= i; k++){
                res = res * 10 + k;
                add = add * 10 + 1;
            }
            for (int j = 0; i + j < 10; j++){
                if (res + add * j >= low && res + add * j <= high) ans.push_back(res + add * j);
                if (res + add * j > high) return ans;
            }
        }
        return ans;
    }
};

int main(){
    int low = 100;
    int high = 300;
    // int low = 1000;
    // int high = 13000;
    // int low = 10;
    // int high = 1000000000;
    Solution S;
    vector<int> ans = S.sequentialDigits(low, high);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}