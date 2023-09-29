#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

#define ll long long

class Solution {
public:
    int n;
    int skill_size;
    unordered_map<string,int> skill_map;
    unordered_map<int, ll> team_map;
    vector<int> people_skill;
    vector<ll> dp;

    int count_people(ll team){
        int ans = 0;
        while(team > 0){
            if (team & 1) ans++;
            team = team >> 1;
        }
        return ans;
    }

    ll find_team(int skill_mask){
        if (skill_mask == 0) return 0;
        if (dp[skill_mask] != -1) return dp[skill_mask];
        for (int i = 0; i < n; i++){
            int small_skill_mask = skill_mask & ~people_skill[i];
            if (small_skill_mask != skill_mask){
                ll new_team_mask = find_team(small_skill_mask) | (1LL << i);
                if (dp[skill_mask] == -1 || count_people(new_team_mask) < count_people(dp[skill_mask])) dp[skill_mask] = new_team_mask;
            }
        }
        return dp[skill_mask];
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = people.size();
        skill_size = 0;
        for (auto skill : req_skills) skill_map[skill] = skill_size++;
        // for(int s = 0; s < skill_size; s++) cout << req_skills[s] << " " << skill_map[req_skills[s]] << endl;
        people_skill = vector<int>(n);
        dp = vector<ll>(1 << skill_size, -1);
        
        for (int i = 0; i < n; i++){
            for (string skill : people[i]) people_skill[i] |= 1 << skill_map[skill];
            // cout << people_skill[i] << endl;
        }

        ll answer = (1 << skill_size) - 1;
        ll team = find_team(answer);
        vector<int> ans;
        for (int i = 0; i < n; i++){
            if (team & (1LL << i)) ans.push_back(i);
        }
        return ans;
    }
};

int main(){
    vector<string> req_skills = {"java","nodejs","reactjs"};
    vector<vector<string>> people = {{"java"},{"nodejs"},{"nodejs","reactjs"}};
    // vector<string> req_skills = {"algorithms","math","java","reactjs","csharp","aws"};
    // vector<vector<string>> people = {{"algorithms","math","java"},{"algorithms","math","reactjs"},{"java","csharp","aws"},{"reactjs","csharp"},{"csharp","math"},{"aws","java"}};
    Solution S;
    vector<int> ans = S.smallestSufficientTeam(req_skills, people);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}