#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<vector<bool>> skill(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++){
            vector<int>& l = languages[i];
            for (int k : l) skill[i][k-1] = true;
        }

        unordered_set<int> s;
        for (auto& f : friendships){
            int a = f[0] - 1;
            int b = f[1] - 1;
            bool communicate = false;
            for (int i = 0; i < n; i++) if (skill[a][i] && skill[b][i]) communicate = true;
            if (!communicate){
                s.insert(a);
                s.insert(b);
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++){
            int teach = 0;
            for (auto k : s){
                if (!skill[k][i]){
                    skill[k][i] = true;
                    teach++;
                }
            }
            ans = min(ans, teach);
        }
        return ans;
    }
};

int main(){
    int n = 2;
    vector<vector<int>> languages = {{1},{2},{1,2}};
    vector<vector<int>> friendships = {{1,2},{1,3},{2,3}};
    // int n = 3;
    // vector<vector<int>> languages = {{2},{1,3},{1,2},{3}};
    // vector<vector<int>> friendships = {{1,4},{1,2},{3,4},{2,3}};
    Solution S;
    cout << S.minimumTeachings(n, languages, friendships) << endl;
    return 0;
}