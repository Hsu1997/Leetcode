#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int k_size = 0;
        int temp = k;
        while(temp > 0) temp /= 10, k_size++;
        if (k_size > n){
            vector<int> empty(k_size - n, 0);
            num.insert(num.begin(), empty.begin(), empty.end());
        }
        // for (auto i : num) cout << i << " ";
        // cout << endl;
        int carry = 0;
        for (int i = num.size()-1; i >= 0; i--){
            num[i] = num[i] + (k % 10) + carry;
            carry = 0;
            k /= 10;
            if (num[i] > 9){
                carry = num[i] / 10;
                num[i] %= 10;
            }
        }
        if (carry) num.insert(num.begin(), carry);
        return num;
    }
};

int main(){
    // vector<int> num = {1,2,0,0};
    // int k = 34;
    // vector<int> num = {2,7,4};
    // int k = 181;
    vector<int> num = {2,7,4};
    int k = 999999;
    Solution S;
    vector<int> ans = S.addToArrayForm(num, k);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}