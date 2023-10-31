#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        if (pref.size() < 2) return pref;
        int temp = pref[0];
        for (int i = 1; i < pref.size(); i++){
            pref[i] ^= temp;
            temp ^= pref[i];
        }
        return pref;
    }
};

int main(){
    vector<int> pref = {5,2,0,3,1};
    // vector<int> pref = {13};
    Solution S;
    vector<int> ans = S.findArray(pref);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}