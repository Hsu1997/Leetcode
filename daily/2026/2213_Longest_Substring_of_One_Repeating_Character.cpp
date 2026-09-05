#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    void addInterval(int left, int right, map<int,int>& interval, unordered_map<int,int>& cnt, priority_queue<int>& pq){
        if (left > right) return;
        interval[left] = right;
        int len = right - left + 1;
        cnt[len]++;
        pq.push(len);
        return;
    }
    void removeInterval(map<int,int>& interval, map<int,int>::iterator it, unordered_map<int,int>& cnt){
        int len = it->second - it->first + 1;
        cnt[len]--;
        interval.erase(it);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int start = 0;
        map<int,int> interval;
        priority_queue<int> pq;
        unordered_map<int,int> cnt;
        for (int i = 1; i < n; i++){
            if (s[i] != s[i-1]){
                interval[start] = i - 1;
                int currLen = i - start;
                start = i;
                pq.push(currLen);
                cnt[currLen]++;
            }
        }
        interval[start] = n - 1;
        pq.push(n - start);
        cnt[n - start]++;
        int q = queryIndices.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++){
            int currPos = queryIndices[i];
            char currChar = queryCharacters[i];
            if (currChar != s[currPos]){
                auto it = prev(interval.upper_bound(currPos));
                int left = it->first;
                int right = it->second;
                removeInterval(interval, it, cnt);
                addInterval(left, currPos - 1, interval, cnt, pq);
                addInterval(currPos, currPos, interval, cnt, pq);
                addInterval(currPos + 1, right, interval, cnt, pq);
                s[currPos] = currChar;
                auto currInterval = interval.find(currPos);
                if (currInterval != interval.begin() && s[prev(currInterval)->second] == currChar){
                    int preLeft = prev(currInterval)->first;
                    removeInterval(interval, prev(currInterval), cnt);
                    removeInterval(interval, currInterval, cnt);
                    addInterval(preLeft, currPos, interval, cnt, pq);
                    currInterval = interval.find(preLeft);
                }
                if (next(currInterval) != interval.end() && s[next(currInterval)->first] == currChar){
                    int currLeft = currInterval->first;
                    int nextRight = next(currInterval)->second;
                    removeInterval(interval, next(currInterval), cnt);
                    removeInterval(interval, currInterval, cnt);
                    addInterval(currLeft, nextRight, interval, cnt, pq);
                }
                
            }
            while(!pq.empty() && cnt[pq.top()] == 0) pq.pop();
            ans[i] = pq.top();
        }
        return ans;
    }
};

int main(){
    string s = "babacc";
    string queryCharacters = "bcb";
    vector<int> queryIndices = {1,3,3};
    // string s = "abyzz";
    // string queryCharacters = "aa";
    // vector<int> queryIndices = {2,1};
    Solution S;
    vector<int> ans = S.longestRepeating(s, queryCharacters, queryIndices);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}