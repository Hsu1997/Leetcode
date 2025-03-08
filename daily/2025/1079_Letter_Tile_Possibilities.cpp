#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        unordered_set<string> s;
        vector<bool> visited(n, false);
        string curr;
        dfs(tiles, curr, visited, s);
        return s.size() - 1;
    }
    void dfs(string& tiles, string& curr, vector<bool>& visited, unordered_set<string>& s){
        s.insert(curr);
        for (int i = 0; i < tiles.size(); i++){
            if (visited[i] == false){
                visited[i] = true;
                curr.push_back(tiles[i]);
                dfs(tiles, curr, visited, s);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }
};

int main(){
    string tiles = "AAB";
    // string tiles = "AAABBC";
    // string tiles = "V";
    Solution S;
    cout << S.numTilePossibilities(tiles) << endl;
    return 0;
}