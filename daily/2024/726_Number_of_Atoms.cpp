#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

// O(N^2)
// class Solution {
// public:
//     string formula;
//     int s;
//     unordered_map<int,int> parenthese;

//     unordered_map<string,int> helper(int start, int end){
//         unordered_map<string,int> ans;
//         if (start >= s || start >= end) return ans;

//         unordered_map<string,int> temp_ans;
//         if (formula[start] == '('){
//             temp_ans = helper(start+1, parenthese[start]);
//             start = parenthese[start]+1;
//         }
//         else{
//             string temp;
//             temp += formula[start++];
//             while(start < s && start < end && formula[start] >= 'a' && formula[start] <= 'z'){
//                 temp += formula[start++];
//             }
//             temp_ans[temp] = 1;
//         }


//         string temp_count;
//         while(start < s && start < end && formula[start] >= '0' && formula[start] <= '9'){
//             temp_count += formula[start++];
//         }
//         int count = (temp_count.empty())? 1 : stoi(temp_count);
//         for (auto i : temp_ans) ans[i.first] += i.second * count;

//         unordered_map<string,int> remain = helper(start, end);
//         for (auto i : remain) ans[i.first] += i.second;
//         return ans;
//     }

//     string countOfAtoms(string _formula) {
//         formula = _formula;
//         s = formula.size();
//         stack<int> sta;
//         for (int i = 0; i < s; i++){
//             if (formula[i] == '(') sta.push(i);
//             else if (formula[i] == ')') parenthese[sta.top()] = i, sta.pop();
//             else continue;
//         }
//         unordered_map<string,int> count_map = helper(0, s);
//         map<string,int> sorted_map(count_map.begin(), count_map.end());
//         string ans;
//         for (auto i : sorted_map){
//             // cout << i.first << " : " << i.second << endl;
//             ans += i.first;
//             if (i.second > 1) ans += to_string(i.second);
//         }
//         return ans;
//     }
// };

// O(N)
class Solution {
public:
    unordered_map<int,int> parenthese;
    unordered_map<int,int> multiply;

    string countOfAtoms(string formula) {
        find_pair(formula);
        find_multiply(formula);
        // for (auto i : multiply) cout << i.first << " : " << i.second << endl;
        unordered_map<string,int> m;
        string temp_atom;
        string temp_count;
        int mul = 1;
        int index = 0;
        while(index < formula.length()){
            if (formula[index] == '(') mul *= multiply[index++];
            else if (formula[index] == ')'){
                mul /= multiply[index++];
                while(index < formula.length() && isdigit(formula[index])) index++;
            }
            else{
                temp_atom = formula[index++];
                while(index < formula.length() && islower(formula[index])) temp_atom += formula[index++];
                temp_count = "";
                while(index < formula.length() && isdigit(formula[index])) temp_count += formula[index++];
                int c = (temp_count.empty())? 1 : stoi(temp_count);
                m[temp_atom] += c * mul;
            }
        }
        // if (!temp_atom.empty()) m[temp_atom] += temp_count.empty()? 1 : stoi(temp_count);
        
        map<string,int> sorted_map(m.begin(), m.end());
        string ans;
        for (auto &[atom, count] : sorted_map){
            ans += atom;
            if (count > 1) ans += to_string(count);
        }
        return ans;
    }

    void find_pair(string& s){
        stack<int> sta;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '(') sta.push(i);
            else if (s[i] == ')') parenthese[sta.top()] = i, sta.pop();
        }
        return;
    }

    void find_multiply(string& s){
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '('){
                string mul;
                int index = parenthese[i]+1;
                while(index < s.length() && isdigit(s[index])) mul += s[index++];
                int m = (mul.empty())? 1 : stoi(mul);
                multiply[i] = m;
                multiply[parenthese[i]] = m;
            }
        }
        return;
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