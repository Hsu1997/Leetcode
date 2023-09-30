#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> s;
        for (auto i : asteroids){
            if (i > 0){
                s.push(i);
            }
            else{
                if (s.empty()) ans.push_back(i);
                while(!s.empty()){
                    if (s.top() < -i){
                        s.pop();
                        if (s.empty()) ans.push_back(i);
                    }
                    else if (s.top() == -i){
                        s.pop();
                        break;
                    }
                    else break;
                }
            }
        }
        vector<int> temp;
        while(!s.empty()) temp.push_back(s.top()), s.pop();
        reverse(temp.begin(), temp.end());
        ans.insert(ans.end(), temp.begin(), temp.end());
        return ans;
    }
};

int main(){
    // vector<int> asteroids = {5,10,-5};
    // vector<int> asteroids = {8,-8};
    vector<int> asteroids = {10,2,-5};
    Solution S;
    vector<int> ans = S.asteroidCollision(asteroids);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}