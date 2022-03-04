#include <iostream>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     double champagneTower(int poured, int query_row, int query_glass){
//         double answer = ans(poured, query_row, query_glass);
//         return min((double)1, answer);
//     }
//     double ans(int poured, int query_row, int query_glass) {
//         if (query_glass < 0 || query_glass > query_row) return 0;
//         if (query_row == 0) return poured;
//         double right = max((double)0, (ans(poured, query_row - 1, query_glass) - 1) / 2 );
//         // cout << "from right : " << right << endl;
//         double left = max((double)0, (ans(poured, query_row - 1, query_glass - 1) - 1) / 2);
//         // cout << "from left : " << left << endl;
//         if (query_glass == 0) return right;
//         if (query_glass == query_row) return left;
//         return left + right;
//     }
// };

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass){
        double now[101][101] = {0};
        now[0][0] = poured;
        double flow;
        for (int i = 0; i < query_row; i++){
            for (int j = 0; j <= i; j++){
                flow = (now[i][j] - 1) / 2;
                if (flow > 0){
                    now[i+1][j] += flow;
                    now[i+1][j+1] += flow;
                }
            }
        }
        return min((double)1, now[query_row][query_glass]);
    }
};

int main(){
    Solution S;
    cout << S.champagneTower(100000009,30,17) << endl;
    return 0;
}