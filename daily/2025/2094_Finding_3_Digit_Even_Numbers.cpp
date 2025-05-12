#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int i : digits) count[i]++;
        vector<int> ans;
        for (int i = 100; i < 1000; i += 2){
            int single = i % 10;
            int ten = (i % 100) / 10;
            int hundred = i / 100;
            count[single]--;
            count[ten]--;
            count[hundred]--;
            if (count[single] >= 0 && count[ten] >= 0 && count[hundred] >= 0) ans.push_back(i);
            count[single]++;
            count[ten]++;
            count[hundred]++;
        }
        return ans;
    }
};

int main(){
    vector<int> digits = {2,1,3,0};
    // vector<int> digits = {2,2,8,8,2};
    // vector<int> digits = {3,7,5};
    Solution S;
    vector<int> ans = S.findEvenNumbers(digits);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}