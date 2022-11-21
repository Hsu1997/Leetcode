#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    float interpolation(int startx, int starty, int nowx, int nowy, int findx){
        float ans = (float)starty + (float)(nowy - starty) / (float)(nowx - startx) * (findx - startx);
        // cout << startx << " " << starty << " => " << nowx << " " << nowy << " : " << findx << " " << ans << endl;
        return ans;
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> ans;
        sort(trees.begin(), trees.end());
        
        // for (auto i : trees){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        // cout << "---------------------------" << endl;

        vector<bool> chosen(trees.size(), false);
        vector<int> count_up = {0};
        // cout << "push : " << trees[0][0] << " " << trees[0][1] << endl;

        for (int i = 1; i < trees.size(); i++){
            if (trees[i][0] == trees[i-1][0]) continue;
            bool stop = false;
            while(!stop && count_up.size() >= 2){
                stop = true;
                int nowx = trees[i][0];
                int nowy = trees[i][1];
                int prex = trees[count_up.back()][0];
                int prey = trees[count_up.back()][1];
                int startx = trees[count_up[count_up.size()-2]][0];
                int starty = trees[count_up[count_up.size()-2]][1];
                if (interpolation(startx, starty, nowx, nowy, prex) < prey){
                    stop = false;
                    chosen[count_up.back()] = false;
                    count_up.pop_back();
                    // cout << "del : " << prex << " " << prey << endl;
                }
            }
            chosen[i] = true;
            count_up.push_back(i);
            // cout << "push : " << trees[i][0] << " " << trees[i][1] << endl;
        }
        // for (auto i : count_up) cout << i << " ";
        // cout << endl;
        // cout << "---------------------------" << endl;
        
        
        vector<int> count_down = {(int)trees.size()-1};
        // cout << "push : " << trees[trees.size()-1][0] << " " << trees[trees.size()-1][1] << endl;
        for (int i = trees.size()-2; i >= 0; i--){
            if (trees[i][0] == trees[i+1][0]) continue;
            bool stop = false;
            while(!stop && count_down.size() >= 2){
                stop = true;
                int nowx = trees[i][0];
                int nowy = trees[i][1];
                int prex = trees[count_down.back()][0];
                int prey = trees[count_down.back()][1];
                int startx = trees[count_down[count_down.size()-2]][0];
                int starty = trees[count_down[count_down.size()-2]][1];
                if (interpolation(startx, starty, nowx, nowy, prex) > prey){
                    stop = false;
                    count_down.pop_back();
                    // cout << "del : " << prex << " " << prey << endl;
                }
            }
            count_down.push_back(i);
            // cout << "push : " << trees[i][0] << " " << trees[i][1] << endl;
        }
        // for (auto i : count_down) cout << i << " ";
        // cout << endl;
        // cout << "---------------------------" << endl;

        for (int i = 1; i < trees.size(); i++){
            if (trees[i][0] == trees[i-1][0]) chosen[i] = true;
            else break;
        }
        for (int i = trees.size()-2; i >= 0; i--){
            if (trees[i][0] == trees[i+1][0]) chosen[i] = true;
            else break;
        }
        for (auto i : count_up) chosen[i] = true;
        for (auto i : count_down) chosen[i] = true;
        for (int i = 0; i < trees.size(); i++){
            if (chosen[i]) ans.push_back(trees[i]);
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> trees = {{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};
    // vector<vector<int>> trees = {{2,0},{4,0},{6,0}};
    // vector<vector<int>> trees = {{3,7},{6,8},{7,8},{11,10},{4,3},{8,5},{7,13},{4,13}};
    vector<vector<int>> trees = {{5,5},{4,8},{1,3},{5,9},{3,0},{0,4},{3,2},{8,9},{9,3}};
    Solution S;
    vector<vector<int>> ans = S.outerTrees(trees);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}

// [[3,0],[4,0],[5,0],[6,1],[7,2],[7,3],[7,4],[6,5],[5,5],[4,5],[3,5],[2,5],[1,4],[1,3],[1,2],[2,1],[4,2],[0,3]]
// [[5,5],[4,8],[1,3],[5,9],[3,0],[0,4],[3,2],[8,9],[9,3]]