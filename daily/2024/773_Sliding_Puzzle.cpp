#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string convert(vector<vector<int>>& board){
        string s;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 3; j++){
                s += to_string(board[i][j]);
            }
        }
        return s;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<string, int> m;
        vector<vector<int>> final = {{1,2,3},{4,5,0}};
        string ans = convert(final);
        string start = convert(board);
        if (ans == start) return 0;

        m[start] = 0;
        queue<string> q;
        q.push(start);

        while(!q.empty()){
            string state = q.front();
            int move = m[state];
            q.pop();
            int zero = state.find('0');
            if (zero >= 3){
                swap(state[zero], state[zero-3]);
                if (m.find(state) == m.end()){
                    m[state] = move + 1;
                    q.push(state);
                }
                swap(state[zero], state[zero-3]);
            }
            if (zero < 3){
                swap(state[zero], state[zero+3]);
                if (m.find(state) == m.end()){
                    m[state] = move + 1;
                    q.push(state);
                }
                swap(state[zero], state[zero+3]);
            }
            if (zero != 0 && zero != 3){
                swap(state[zero], state[zero-1]);
                if (m.find(state) == m.end()){
                    q.push(state);
                    m[state] = move + 1;
                }
                swap(state[zero], state[zero-1]);
            }
            if (zero != 2 && zero != 5){
                swap(state[zero], state[zero+1]);
                if (m.find(state) == m.end()){
                    q.push(state);
                    m[state] = move + 1;
                }
                swap(state[zero], state[zero+1]);
            }
            if (m.find(ans) != m.end()) return m[ans];
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> board = {{1,2,3},{4,0,5}};
    // vector<vector<int>> board = {{1,2,3},{5,4,0}};
    // vector<vector<int>> board = {{4,1,2},{5,0,3}};

    Solution S;
    cout << S.slidingPuzzle(board) << endl;
    return 0;
}