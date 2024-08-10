#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Union_set {
public:
    Union_set(int n){
        s.resize(n);
        for (int i = 0; i < n; i++) s[i] = i;
    }
    int search(int i){
        return s[i] = (s[i] == i)? i : search(s[i]);
    }
    void combine(int i, int j){
        int x = search(i);
        int y = search(j);
        s[y] = x;
    }
    int set_size(){
        unordered_set<int> count;
        for (int i = 0; i < s.size(); i++) count.insert(search(i));
        return count.size();
    }
private:
    vector<int> s;
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        Union_set u(n*n*4);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int index = i * n + j;
                if (grid[i][j] == '/'){
                    u.combine(index * 4, index * 4 + 3);
                    u.combine(index * 4 + 1, index * 4 + 2);
                }
                else if (grid[i][j] == '\\'){
                    u.combine(index * 4, index * 4 + 1);
                    u.combine(index * 4 + 2, index * 4 + 3);
                }
                else{
                    u.combine(index * 4, index * 4 + 1);
                    u.combine(index * 4, index * 4 + 2);
                    u.combine(index * 4, index * 4 + 3);
                }
                if (i > 0) u.combine(index * 4, ((i - 1) * n + j) * 4 + 2);
                if (j > 0) u.combine(index * 4 + 3, (index - 1) * 4 + 1);
                if (i < n-1) u.combine(index * 4 + 2, ((i + 1) * n + j) * 4);
                if (j < n-1) u.combine(index * 4 + 1, (index + 1) * 4 + 3);
            }
        }
        return u.set_size();
    }
};

int main(){
    // vector<string> grid = {" /","/ "};
    // vector<string> grid = {" /","  "};
    vector<string> grid = {"/\\","\\/"};
    Solution S;
    cout << S.regionsBySlashes(grid) << endl;
    return 0;
}