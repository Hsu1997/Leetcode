#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    string formula;
    int s;
    unordered_map<int,int> parenthese;

    unordered_map<string,int> helper(int start, int end){
        unordered_map<string,int> ans;
        if (start >= s || start >= end) return ans;

        unordered_map<string,int> temp_ans;
        if (formula[start] == '('){
            temp_ans = helper(start+1, parenthese[start]);
            start = parenthese[start]+1;
        }
        else{
            string temp;
            temp += formula[start++];
            while(start < s && start < end && formula[start] >= 'a' && formula[start] <= 'z'){
                temp += formula[start++];
            }
            temp_ans[temp] = 1;
        }


        string temp_count;
        while(start < s && start < end && formula[start] >= '0' && formula[start] <= '9'){
            temp_count += formula[start++];
        }
        int count = (temp_count.empty())? 1 : stoi(temp_count);
        for (auto i : temp_ans) ans[i.first] += i.second * count;

        unordered_map<string,int> remain = helper(start, end);
        for (auto i : remain) ans[i.first] += i.second;
        return ans;
    }

    string countOfAtoms(string _formula) {
        formula = _formula;
        s = formula.size();
        stack<int> sta;
        for (int i = 0; i < s; i++){
            if (formula[i] == '(') sta.push(i);
            else if (formula[i] == ')') parenthese[sta.top()] = i, sta.pop();
            else continue;
        }
        unordered_map<string,int> count_map = helper(0, s);
        map<string,int> sorted_map(count_map.begin(), count_map.end());
        string ans;
        for (auto i : sorted_map){
            // cout << i.first << " : " << i.second << endl;
            ans += i.first;
            if (i.second > 1) ans += to_string(i.second);
        }
        return ans;
    }
};

int main(){
    // string formula = "H2O";
    // string formula = "Mg(OH)2";
    string formula = "K4(ON(SO3)2)2";
    Solution S;
    cout << S.countOfAtoms(formula) << endl;
    return 0;
}