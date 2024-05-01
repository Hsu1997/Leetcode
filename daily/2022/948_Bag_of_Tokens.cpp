#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int i = 0;
        int j = tokens.size()-1;
        sort(tokens.begin(), tokens.end());

        while(i < j){
            if (power >= tokens[i]){
                power -= tokens[i];
                i++;
                score++;
            }
            else if (tokens[i] <= tokens[j] && score > 0){
                power += (tokens[j] - tokens[i]);
                i++;
                j--;
            }
            else break;
            // cout << "i = " << i << ", j = " << j << ", power = " << power << ", score = " << score << endl;
        }

        if (i == j && power >= tokens[i]) score++;
        return score;
    }
};

int main(){
    vector<int> tokens = {71,55,82};
    int power = 54;
    // vector<int> tokens = {100,200,300,400};
    // int power = 200;
    Solution S;
    cout << S.bagOfTokensScore(tokens, power) << endl;
    return 0;
}