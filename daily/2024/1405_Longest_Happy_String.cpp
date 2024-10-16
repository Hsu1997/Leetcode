#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});
        string ans;
        while(!pq.empty()){
            auto [count1, char1] = pq.top();
            pq.pop();
            if (pq.empty()){
                if (ans.empty() || ans.back() != char1){
                    ans.push_back(char1);
                    count1--;
                    if (count1) pq.push({count1, char1});
                }
                break;
            }
            else{
                auto [count2, char2] = pq.top();
                pq.pop();
                ans.push_back(char1);
                ans.push_back(char2);
                count1--, count2--;
                if (count1) pq.push({count1, char1});
                if (count2) pq.push({count2, char2});
            }
        }
        if (!pq.empty()){
            auto [count, curr] = pq.top();
            pq.pop();
            string ans_new;
            for (int i = 0; i < ans.length(); i++){
                ans_new.push_back(ans[i]);
                if (ans[i] == curr && count){
                    ans_new.push_back(curr);
                    count--;
                }
            }
            return ans_new;
        }
        return ans;
    }
};

int main(){
    // int a = 1;
    // int b = 1;
    // int c = 7;
    // int a = 7;
    // int b = 1;
    // int c = 0;
    // int a = 2;
    // int b = 2;
    // int c = 2;
    int a = 0;
    int b = 0;
    int c = 7;
    Solution S;
    cout << S.longestDiverseString(a, b, c) << endl;
    return 0;
}