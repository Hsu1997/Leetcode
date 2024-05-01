#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.resize(n+1);
        ans.at(0) = 0;
        int power_of_two = 1;
        for (int i = 1; i <= n; i++){
            if (i == power_of_two){
                ans.at(i) = 1;
                power_of_two *= 2;
            }
            ans.at(i) = 1 + ans.at(i - power_of_two/2);
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    Solution S;
    vector<int> ans = S.countBits(n);
    for (auto i : ans) cout << i << " ";
    cout << endl;

    // 0   0000    0
    // 1   0001    1

    // 2   0010    1
    // 3   0011    2

    // 4   0100    1
    // 5   0101    2
    // 6   0110    2
    // 7   0111    3
    
    // 8   1000    1
    // 9   1001    2
    // 10  1010    2
    // 11  1011    3
    // 12  1100    2
    // 13  1101    3
    // 14  1110    3
    // 15  1111    4

    // 16  10000   5

    return 0;
}