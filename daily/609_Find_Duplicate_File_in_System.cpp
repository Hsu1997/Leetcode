#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        map<string, vector<string>> m;
        for (string s : paths){
            int i = 0;
            while (s[i] != ' ') i++;
            string path = s.substr(0, i);
            i++;
            while (i < s.length()){
                int j = i;
                while(j < s.length() && s[j] != '.') j++;
                string file = s.substr(i, j-i);
                j += 5;
                int k = j;
                while(s[k] != ')') k++;
                string content = s.substr(j, k-j);
                m[content].push_back(path+ "/" + file + ".txt");
                // cout << content << " : " << path+ "/" + file + ".txt" << endl;
                i = k+2;
            }
        }
        
        for (auto it = m.begin(); it != m.end(); it++){
            if (it->second.size() > 1) ans.push_back(it->second);
        }
        
        return ans;
    }
};

int main(){
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"};
    // vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"};
    Solution S;
    vector<vector<string>> ans = S.findDuplicate(paths);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}