#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double eps = 1e-6;

    bool search(vector<double> curr){
        int n = curr.size();
        if (n == 1) return fabs(curr[0] - 24.0) < eps;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                vector<double> next;
                for (int k = 0; k < n; k++){
                    if (k != i && k != j) next.push_back(curr[k]);
                }
                double a = curr[i] + curr[j];
                next.push_back(a);
                if (search(next)) return true;
                next.pop_back();
                a = curr[i] - curr[j];
                next.push_back(a);
                if (search(next)) return true;
                next.pop_back();
                a = curr[j] - curr[i];
                next.push_back(a);
                if (search(next)) return true;
                next.pop_back();
                a = curr[i] * curr[j];
                next.push_back(a);
                if (search(next)) return true;
                next.pop_back();
                a = curr[i] / curr[j];
                next.push_back(a);
                if (search(next)) return true;
                next.pop_back();
                a = curr[j] / curr[i];
                next.push_back(a);
                if (search(next)) return true;
                next.pop_back();
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> curr;
        for (int i : cards) curr.push_back((double)i);
        return search(curr);
    }
};

int main(){
    vector<int> cards = {4,1,8,7};
    // vector<int> cards = {1,2,1,2};
    // vector<int> cards = {3,3,8,8};
    Solution S;
    cout << S.judgePoint24(cards) << endl;
    return 0;
}