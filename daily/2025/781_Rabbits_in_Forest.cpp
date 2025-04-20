#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> rabbit;
        int ans = 0;
        for (int i : answers){
            if (i == 0) ans++;
            else{
                if (rabbit[i] == 0){
                    ans += i + 1;
                    rabbit[i] = i;
                }
                else rabbit[i]--;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> answers = {1,1,2};
    // vector<int> answers = {10,10,10};
    // vector<int> answers = {1,0,1,0,0};
    // vector<int> answers = {0,0,1,1,1};
    Solution S;
    cout << S.numRabbits(answers) << endl;
    return 0;
}