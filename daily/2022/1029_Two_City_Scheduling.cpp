#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int a_count, b_count;
        int ans = 0;
        vector<int> a, b;
        a_count = b_count = 0;
        for (auto i : costs){
            if (i[0] < i[1]){
                a_count++;
                ans += i[0];
                a.push_back(i[1]-i[0]);
                // cout << "ans = " << ans << ", a push " << a.back() << endl;
            }
            else{
                b_count++;
                ans += i[1];
                b.push_back(i[0]-i[1]);
                // cout << "ans = " << ans << ", b push " << b.back() << endl;
            }
        }
        // cout << a_count << " " << b_count << endl;
        if (a_count < b_count){
            sort(b.begin(), b.end());
            for (int i = 0; i < (b_count - a_count) / 2; i++) ans += b[i];
        }
        if (a_count > b_count){
            sort(a.begin(), a.end());
            for (int i = 0; i < (a_count - b_count) / 2; i++) ans += a[i];
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> costs = {{10,20},{30,200},{400,50},{30,20}};
    // vector<vector<int>> costs = {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};
    // vector<vector<int>> costs = {{515,563},{451,713},{537,709},{343,819},{855,779},{457,60},{650,359},{631,42}};
    vector<vector<int>> costs = {{518,518},{71,971},{121,862},{967,607},{138,754},{513,337},{499,873},{337,387},{647,917},{76,417}};
    // 3671
    Solution S;
    cout << S.twoCitySchedCost(costs) << endl;
    return 0;
}