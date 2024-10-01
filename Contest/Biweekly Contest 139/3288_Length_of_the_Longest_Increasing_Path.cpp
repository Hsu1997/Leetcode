#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int find_longest(vector<vector<int>>& coordinates){
        vector<int> seq;
        for (auto& coor : coordinates){
            int y = coor[1];
            auto it = lower_bound(seq.begin(), seq.end(), y);
            if (it == seq.end()) seq.push_back(y);
            else *it = y;
        }
        return seq.size();
    }
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        vector<vector<int>> left;
        vector<vector<int>> right;
        for (vector<int>& coor : coordinates){
            if (coor[0] < coordinates[k][0] && coor[1] < coordinates[k][1]) left.push_back(coor);
            if (coor[0] > coordinates[k][0] && coor[1] > coordinates[k][1]) right.push_back(coor);
        }
        auto cmp = [](vector<int>& a, vector<int>& b){
            if (a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        };
        sort(left.begin(), left.end(), cmp);
        // for (auto i : left){
        //     cout << i[0] << " " << i[1] << endl;
        // }
        // cout << endl;
        sort(right.begin(), right.end(), cmp);
        // for (auto i : right){
        //     cout << i[0] << " " << i[1] << endl;
        // }

        // int n1 = left.size();
        // int n2 = right.size();
        int ans_left = find_longest(left);
        int ans_right = find_longest(right);
        // if (n1){
        //     vector<int> dp_left(n1, 0);
        //     for (int i = 0; i < n1; i++){
        //         int temp = 0;
        //         int x = left[i][0];
        //         int y = left[i][1];
        //         for (int j = i-1; j >= 0; j--){
        //             if (left[j][0] < x && left[j][1] < y) temp = max(temp, dp_left[j]);
        //         }
        //         dp_left[i] = 1 + temp;
        //         ans_left = max(ans_left, dp_left[i]);
        //     }
        // }
        // if (n2){
        //     vector<int> dp_right(n2, 0);
        //     for (int i = 0; i < n2; i++){
        //         int temp = 0;
        //         int x = right[i][0];
        //         int y = right[i][1];
        //         for (int j = i-1; j >= 0; j--){
        //             if (right[j][0] < x && right[j][1] < y) temp = max(temp, dp_right[j]);
        //         }
        //         dp_right[i] = 1 + temp;
        //         ans_right = max(ans_right, dp_right[i]);
        //     }
        // }
        return ans_left + ans_right + 1;
    }
};

int main(){
    vector<vector<int>> coordinates = {{3,1},{2,2},{4,1},{0,0},{5,3}};
    int k = 1;
    // vector<vector<int>> coordinates = {{2,1},{7,0},{5,6}};
    // int k = 2;
    Solution S;
    cout << S.maxPathLength(coordinates, k) << endl;
    return 0;
}