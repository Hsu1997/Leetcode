#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        int ans = 0;
        unordered_set<int> s;
        for (int i = 0; i < n; i++){
            if (digits[i] == 0) continue;
            for (int j = 0; j < n; j++){
                if (i == j) continue;
                for (int k = 0; k < n; k++){
                    if (i == k || j == k || digits[k] % 2 == 1) continue;
                    int curr = 100 * digits[i] + 10 * digits[j] + digits[k];
                    if (s.count(curr) != 0) continue;
                    s.insert(curr);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> digits = {1,2,3,4};
    // vector<int> digits = {0,2,2};
    // vector<int> digits = {6,6,6};
    // vector<int> digits = {1,3,5};
    Solution S;
    cout << S.totalNumbers(digits) << endl;
    return 0;
}

