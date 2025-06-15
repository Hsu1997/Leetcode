#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (groups[i] == groups[j] || words[i].length() != words[j].length()) continue;
                int diff = 0;
                for (int k = 0; k < words[i].length(); k++){
                    if (words[i][k] != words[j][k]) diff++;
                }
                if (diff == 1){
                    graph[i].push_back(j);
                    indegree[j]++;
                }
            }
        }
        vector<int> len(n, 0);
        vector<int> from(n, -1);
        queue<int> que;
        for (int i = 0; i < n; i++){
            if (indegree[i] == 0){
                que.push(i);
                len[i] = 1;
            }
        }
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            for (int neighbor : graph[curr]){
                if (len[neighbor] < len[curr] + 1){
                    len[neighbor] = len[curr] + 1;
                    from[neighbor] = curr;
                }
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) que.push(neighbor);
            }
        }
        int l = 0;
        int idx = 0;
        for (int i = 0; i < n; i++){
            if (len[i] > l){
                l = len[i];
                idx = i;
            }
        }
        vector<string> ans;
        while(idx != -1){
            ans.push_back(words[idx]);
            idx = from[idx];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    vector<string> words = {"bab","dab","cab"};
    vector<int> group = {1,2,2};
    // vector<string> words = {"a","b","c","d"};
    // vector<int> group = {1,2,3,4};
    // vector<string> words = {"aab","ca","cbd"};
    // vector<int> group = {3,3,2};
    Solution S;
    vector<string> ans = S.getWordsInLongestSubsequence(words, group);
    for (string s : ans) cout << s << " ";
    cout << endl;
    return 0;
}