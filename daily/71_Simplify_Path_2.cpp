#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        path += '/';
        string temp;
        stack<string> s;
        for (auto i : path){
            if (i ==  '/'){
                if (temp == "." || temp == ""){}
                else if (temp == ".."){
                    if (!s.empty()) s.pop();
                }
                else s.push(temp);
                temp = "";
            }
            else temp += i;
        }
        string ans;
        if (s.empty()) return "/";
        while(!s.empty()){
            ans = "/"  + s.top()+ ans;
            s.pop();
        }
        return ans;
    }
};

int main(){
    string path = "/home/";
    // string path = "/../";
    // string path = "/home//foo/";
    Solution S;
    cout << S.simplifyPath(path) << endl;
    return 0;
}