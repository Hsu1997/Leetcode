#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Chess{
public:
    int n;
    vector<vector<int>> board;
    vector<pair<int,int>> dir = {{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};
    Chess(int n){
        this->n = n;
        board = vector<vector<int>>(n, vector<int>(n, -1));
    }
    bool inBoard(int i, int j){
        return i >= 0 && j >= 0 && i < n && j < n;
    }
    bool dfs(int i, int j, int t){
        if (!inBoard(i, j) || board[i][j] != -1) return false;
        board[i][j] = t;
        if (t == n * n - 1) return true;
    
        // Warnsdorff's heuristic: sort moves by onward degree
        vector<pair<int, pair<int, int>>> moves;
        for (auto d : dir) {
            int ni = i + d.first, nj = j + d.second;
            if (inBoard(ni, nj) && board[ni][nj] == -1) {
                int cnt = 0;
                for (auto d2 : dir) {
                    int nni = ni + d2.first, nnj = nj + d2.second;
                    if (inBoard(nni, nnj) && board[nni][nnj] == -1) cnt++;
                }
                moves.push_back({cnt, {ni, nj}});
            }
        }
        sort(moves.begin(), moves.end());
        for (auto m : moves) {
            if (dfs(m.second.first, m.second.second, t + 1)) return true;
        }
        board[i][j] = -1;
        return false;
    }
    // bool dfs(int i, int j, int t){
    //     if (!inBoard(i, j) || board[i][j] != -1) return false;
    //     if (t == n * n - 1){
    //         board[i][j] = t;
    //         return true;
    //     }
    //     board[i][j] = t;
    //     for (auto d : dir){
    //         int x = d.first;
    //         int y = d.second;
    //         if (dfs(i + x, j + y, t + 1)) return true;
    //     }
    //     board[i][j] = -1;
    //     return false;
    // }
};

bool start_at(int n, int i, int j, Chess& C){
    C.board = vector<vector<int>>(n, vector<int>(n, -1));
    if (C.dfs(i, j, 0)) return true;
    return false;
}

void run(int n){
    Chess C(n);
    bool found = false;
    if (start_at(n, 0, 0, C) || start_at(n, 0, n-1, C) || start_at(n, n-1, 0, C) || start_at(n, n-1, n-1, C)) found = true;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (found) break;
            if (start_at(n, i, j, C)){
                found = true;
                break;
            }
        }
    }
    if (!found) cout << "Not valid answer" << endl;
    auto& ans = C.board;
    for (auto i : ans){
        for (auto j : i){
            cout << setw(3) << j << " ";
        }
        cout << endl;
    }
    return;
}

int main(){
    while(true){
        int n;
        cout << "Enter board size n (<=0 to exit): ";
        cin >> n;
        if (n <= 0) break;
        run(n);
    }
    return 0;
}