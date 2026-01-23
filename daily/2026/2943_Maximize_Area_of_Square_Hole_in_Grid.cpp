#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        if (hBars.empty() || vBars.empty()) return 1;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int hc = 2;
        int vc = 2;
        int hcurr = 2;
        for (int idx = 1; idx < hBars.size(); idx++){
            if (hBars[idx] == hBars[idx-1] + 1){
                hcurr++;
                hc = max(hc, hcurr);
            }
            else{
                hcurr = 2;
            }
        }
        int vcurr = 2;
        for (int idx = 1; idx < vBars.size(); idx++){
            if (vBars[idx] == vBars[idx-1] + 1){
                vcurr++;
                vc = max(vc, vcurr);
            }
            else{
                vcurr = 2;
            }
        }
        return min(hc, vc) * min(hc, vc);

    }
};

int main(){
    int n = 2;
    int m = 1;
    vector<int> hBars = vector{2,3};
    vector<int> vBars = {2};
    // int n = 1;
    // int m = 1;
    // vector<int> hBars = {2};
    // vector<int> vBars = {2};
    // int n = 2;
    // int m = 3;
    // vector<int> hBars = {2,3};
    // vector<int> vBars = {2,4};
    // int n = 3;
    // int m = 2;
    // vector<int> hBars = {3,2,4};
    // vector<int> vBars = {3,2};
    // int n = 10;
    // int m = 46;
    // vector<int> hBars = {10,5,6,8,11,3,2,7,4,9};
    // vector<int> vBars = {7,45,22,9,39,6};
    Solution S;
    cout << S.maximizeSquareHoleArea(n, m, hBars, vBars) << endl;
    return 0;
}