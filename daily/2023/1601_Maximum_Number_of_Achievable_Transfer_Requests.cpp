#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int r = requests.size();
        int ans = 0;
        for (int i = 1; i < (1 << r); i++){
            int one = 0;
            vector<int> c(n, 0);
            for(int d = 0; d < r; d++){
                if ((i >> d) == 0) break;
                if ((i >> d) & 1){
                    one++;
                    c[requests[d][0]]++;
                    c[requests[d][1]]--;
                }
            }
            bool update = true;
            for (auto k : c){
                if (k != 0){
                    update = false;
                    break;
                }
            }
            if (update) ans = max(ans, one);
        }
        return ans;
    }
};

int main(){
    // int n = 5;
    // vector<vector<int>> requests = {{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}};
    // int n = 3;
    // vector<vector<int>> requests = {{0,0},{1,2},{2,1}};
    int n = 4;
    vector<vector<int>> requests = {{0,3},{3,1},{1,2},{2,0}};
    Solution S;
    cout << S.maximumRequests(n, requests) << endl;
    return 0;
}