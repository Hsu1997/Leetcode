#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k--;
        int ans = 0;
        int idx = 0;
        while(k){
            if (k % 2 && operations[idx]) ans++;
            k /= 2;
            idx++;
        }
        return 'a' + (ans % 26);
    }
};

int main(){
    long long k = 5;
    vector<int> operations = {0,0,0};
    // long long k = 10;
    // vector<int> operations = {0,1,0,1};
    Solution S;
    cout << S.kthCharacter(k, operations) << endl;
    return 0;
}