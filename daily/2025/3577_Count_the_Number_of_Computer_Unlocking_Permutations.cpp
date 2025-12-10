#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int mod = 1e9 + 7;
        for (int i = 1; i < n; i++) if (complexity[i] <= complexity[0]) return 0;
        long long ans = 1;
        for (int i = 1; i < n; i++){
            ans = (ans * i) % mod;
        }
        return ans;
    }
};

int main(){
    vector<int> complexity = {1,2,3};
    // vector<int> complexity = {3,3,3,4,4,4};
    // vector<int> complexity = {2,5,3,4,123,7754,123,9765,124436};
    Solution S;
    cout << S.countPermutations(complexity) << endl;
    return 0;
}