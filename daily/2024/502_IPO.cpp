#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> project;
        for (int i = 0; i < n; i++) project.push_back({capital[i], profits[i]});
        sort(project.begin(), project.end());
        priority_queue<int, vector<int>, less<int>> greedy;
        int i = 0;
        for (int r = 0; r < k; r++){
            while(i < n && project[i].first <= w) greedy.push(project[i++].second);
            if (greedy.empty()) return w;
            w += greedy.top();
            greedy.pop();
        }
        return w;
    }
};

int main(){
    int k = 2;
    int w = 0;
    vector<int> profits = {1,2,3};
    vector<int> capital = {0,1,1};
    // int k = 3;
    // int w = 0;
    // vector<int> profits = {1,2,3};
    // vector<int> capital = {0,1,2};
    Solution S;
    cout << S.findMaximizedCapital(k, w, profits, capital) << endl;
    return 0;
}