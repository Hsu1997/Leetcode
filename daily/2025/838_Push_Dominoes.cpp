#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();

        vector<int> push_right_dis(n);
        int dis = -1;
        for (int i = 0; i < n; i++){
            if (dominoes[i] == 'R') dis = 0;
            else if (dominoes[i] == 'L') dis = -1;
            else if (dominoes[i] == '.' && dis != -1) dis++;
            push_right_dis[i] = dis;
        }
        // for (auto i : push_right_dis) cout << i << " ";
        // cout << endl;

        vector<int> push_left_dis(n);
        dis = -1;
        for (int i = n-1; i >= 0; i--){
            if (dominoes[i] == 'L') dis = 0;
            else if (dominoes[i] == 'R') dis = -1;
            else if (dominoes[i] == '.' && dis != -1) dis++;
            push_left_dis[i] = dis;
        }
        // for (auto i : push_left_dis) cout << i << " ";
        // cout << endl;

        string s = dominoes;
        for (int i = 0; i < n; i++){
            if (push_right_dis[i] == -1 && push_left_dis[i] == -1) continue;
            if (push_right_dis[i] == -1) s[i] = 'L';
            else if (push_left_dis[i] == -1) s[i] = 'R';
            else{
                if (push_left_dis[i] == push_right_dis[i]) s[i] = '.';
                else{
                    if (push_left_dis[i] > push_right_dis[i]) s[i] = 'R';
                    else s[i] = 'L';
                }
            }
        }
        return s;
    }
};

int main(){
    string dominoes = "RR.L";
    // string dominoes = ".L.R...LR..L..";
    Solution S;
    cout << S.pushDominoes(dominoes) << endl;
    return 0; 
}