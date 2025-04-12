#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++){
            if (isSymmetric(i)) ans++;
        }
        return ans;
    }
    bool isSymmetric(int _num){
        string num = to_string(_num);
        int n = num.length();
        if (n % 2 == 1) return false;
        int left = 0;
        int right = 0;
        for (int i = 0; i < n/2; i++) left += (num[i] - '0');
        for (int i = n/2; i < n; i++) right += (num[i] - '0');
        return left == right;
    }
};

int main(){
    int low = 1;
    int high = 100;
    // int low = 1200;
    // int high = 1230;
    Solution S;
    cout << S.countSymmetricIntegers(low, high) << endl;
    return 0;
}