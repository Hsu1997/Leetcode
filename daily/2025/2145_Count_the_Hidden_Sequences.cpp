#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long m = 0;
        long long M = 0;
        long long curr = 0;
        for (int d : differences){
            curr += d;
            m = min(m, curr);
            M = max(M, curr);
        }
        return max(1LL * 0, (upper - lower) - (M - m) + 1);
    }
};

int main(){
    vector<int> differences = {1,-3,4};
    int lower = 1;
    int upper = 6;
    // vector<int> differences = {3,-4,5,1,-2};
    // int lower = -4;
    // int upper = 5;
    // vector<int> differences = {4,-7,2};
    // int lower = 3;
    // int upper = 6;
    Solution S;
    cout << S.numberOfArrays(differences, lower, upper) << endl;
    return 0;
}