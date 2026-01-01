#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n-1] += 1;
        for (int i = n - 1; i > 0; i--){
            if (digits[i] > 9){
                digits[i] %= 10;
                digits[i-1] += 1;
            }
            else return digits;
        }
        if (digits[0] > 9){
            digits[0] %= 10;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main(){
    vector<int> digits = {1,2,3};
    // vector<int> digits = {4,3,2,1};
    // vector<int> digits = {9};
    // vector<int> digits = {4,3,2,9};
    // vector<int> digits = {9,9,9,9,9};
    Solution S;
    S.plusOne(digits);
    for (int i : digits) cout << i << " ";
    cout << endl;
    return 0;
}