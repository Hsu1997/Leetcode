#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (auto i : left) ans = max(ans, i);
        for (auto i : right) ans = max(ans, n-i);
        return ans;
    }
};

int main(){
    // int n = 4;
    // vector<int> left = {4,3};
    // vector<int> right = {0,1};
    // int n = 7;
    // vector<int> left = {};
    // vector<int> right = {0,1,2,3,4,5,6,7};
    int n = 7;
    vector<int> left = {0,1,2,3,4,5,6,7};
    vector<int> right = {};
    Solution S;
    cout << S.getLastMoment(n, left, right) << endl;
    return 0;
}