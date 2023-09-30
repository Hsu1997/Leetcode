#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> events;
        for (int i = 0; i < n; i++){
            events.push_back({capital[i],profits[i]});
        }
        sort(events.begin(), events.end());
        // for (auto i : events){
        //     cout << i.first << " " << i.second << endl;
        // }
        priority_queue<int, vector<int>, less<int>> pq;
        int now_capital = w;
        int i = 0;
        int done = 0;
        while(done < k){
            while(i < n && events[i].first <= now_capital){
                pq.push(events[i].second);
                i++;
            }
            if (pq.empty()) return now_capital;
            now_capital += pq.top();
            pq.pop();
            done++;
        }
        return now_capital;
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
    // int k = 1;
    // int w = 0;
    // vector<int> profits = {1,2,3};
    // vector<int> capital = {1,1,2};
    Solution S;
    cout << S.findMaximizedCapital(k,w,profits,capital) << endl;
    return 0;
}