#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// class Solution {
// public:
//     string simplifyPath(string path) {
//         string output = "/";
//         if (path.size() <= 1) return output;
//         int i = 0;
//         int j = 0;
//         while (i != path.size() - 1){
//             i = path.find('/', i);
//             j = path.find('/', i + 1);
//             // cout << "i and j : " << i << "," << j << endl;
//             string temp;
//             if (j == string::npos) temp.assign(path, i + 1, path.size() - i - 1);
//             else temp.assign(path, i + 1, j - i - 1);
//             // cout << "temp = " << temp << endl;
//             if (temp == "" || temp == ".") {}
//             else if (temp == ".."){
//                 if (output.size() > 1){
//                     int k = output.rfind('/', output.size() - 2);
//                     // cout << "k = " << k << endl;
//                     output.erase(k + 1, -1);
//                 }
//             }
//             else{
//                 output.append(temp);
//                 output.append("/");
//             }
//             if (j == string::npos) i = path.size() - 1;
//             else i = j;
//             // cout << "output = " << output << endl;
//         }
//         if (output.size() == 1) return "/";
//         return output.erase(output.size()-1,1);
//    }
// };

class Solution{
public:
        string simplifyPath(string path){
            int length = path.length();
            if (path[length - 1] != '/'){
                path += '/';
                length++;
            }

            stack<string> S;
            string temp = "";
            for (int i = 0; i < length; i++){
                if (path[i] == '/'){
                    if (temp == "" || temp == "."){}
                    else if (temp == ".."){
                        if (!S.empty()) S.pop();
                    }
                    else{
                        S.push(temp);
                    }
                    temp = "";
                }
                else{
                    temp += path[i];
                }
            }
            string output;
            while(!S.empty()){
                output = "/" + S.top() + output;
                S.pop();
            }
            if (output.empty()) return "/";
            return output;
        }
} ;

int main(){
    // string s = "/a/./b/../../c/";
    // ans : "/c"
    string s = "/a//b////c/d//././/..";
    // ans : "/a/b/c"
    Solution S;
    cout << S.simplifyPath(s) << endl;
    return 0;
}