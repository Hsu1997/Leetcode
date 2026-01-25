#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(m);
        vFences.push_back(n);
        unordered_set<int> h;
        for (int i = 0; i < hFences.size(); i++){
            h.insert(hFences[i] - 1);
            for (int j = 0; j < i; j++){
                h.insert(abs(hFences[i] - hFences[j]));
            }
        }
        // for (int i : h) cout << i << " ";
        // cout << endl;
        unordered_set<int> v;
        for (int i = 0; i < vFences.size(); i++){
            v.insert(vFences[i] - 1);
            for (int j = 0; j < i; j++){
                v.insert(abs(vFences[i] - vFences[j]));
            }
        }
        // for (int i : v) cout << i << " ";
        // cout << endl;
        int res = -1;
        for (int i : h) if (v.find(i) != v.end()) res = max(res, i);
        if (res == -1) return -1;
        long long ans = (1LL * res * res) % (int(1e9 + 7));
        return ans;
    }
};

int main(){
    int m = 4;
    int n = 3;
    vector<int> hFences = {2,3};
    vector<int> vFences = {2};
    // int m = 6;
    // int n = 7;
    // vector<int> hFences = {2};
    // vector<int> vFences = {4};
    // int m = 3;
    // int n = 9;
    // vector<int> hFences = {2};
    // vector<int> vFences = {8,6,5,4};
    Solution S;
    cout << S.maximizeSquareArea(m, n, hFences, vFences) << endl;
    return 0;
}