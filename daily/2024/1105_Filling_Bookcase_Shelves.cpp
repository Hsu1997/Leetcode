#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    void dfs(vector<vector<int>>& books, int shelfWidth, int index, int curWidth, int curHeight, int totalHeight){
        if (index == books.size()) return;
        int bookWidth = books[index][0];
        int bookHeight = books[index][1];
        // Put on the same level
        if (curWidth + bookWidth <= shelfWidth){
            int AddedHeight = max(0, bookHeight - curHeight);
            if (totalHeight + AddedHeight < dp[index][curWidth + bookWidth]){
                dp[index][curWidth + bookWidth] = totalHeight + AddedHeight;
                dfs(books, shelfWidth, index+1, curWidth+bookWidth, curHeight+AddedHeight, totalHeight+AddedHeight);
            }
        }
        // Put on the next level
        dp[index][bookWidth] = min(dp[index][bookWidth], totalHeight+bookHeight);
        dfs(books, shelfWidth, index+1, bookWidth, bookHeight, totalHeight + bookHeight);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        dp = vector<vector<int>>(books.size(), vector<int>(shelfWidth+1, INT_MAX));
        dfs(books, shelfWidth, 0, 0, 0, 0);
        return *min_element(dp[books.size()-1].begin(), dp[books.size()-1].end());
    }
};

int main(){
    vector<vector<int>> books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    int shelfWidth = 4;
    // vector<vector<int>> books = {{1,3},{2,4},{3,2}};
    // int shelfWidth = 6;
    Solution S;
    cout << S.minHeightShelves(books, shelfWidth) << endl;
    return 0;
}