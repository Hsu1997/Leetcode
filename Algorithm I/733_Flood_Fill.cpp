#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int row, col , color;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        row = image.size();
        col = image[0].size();
        color = image[sr][sc];
        if (color == newColor) return image;
        spread(image, sr, sc, newColor);
        return image;   
    }

    void spread(vector<vector<int>>& image, int sr, int sc, int newColor){
        if (image[sr][sc] == color){
            image[sr][sc] = newColor;
            if (sr >= 1) spread(image, sr-1, sc, newColor);
            if (sr < row-1) spread(image, sr+1, sc, newColor);
            if (sc >= 1) spread(image, sr, sc-1, newColor);
            if (sc < col-1) spread(image, sr, sc+1, newColor);
        }
    }
};

int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    Solution S;
    S.floodFill(image, 1, 1, 2);
    for (auto &row : image){
        for (auto &col : row){
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}