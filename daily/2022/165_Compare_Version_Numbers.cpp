#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        string delimiter = ".";
        vector<string> v1, v2;
        int pos = 0;
        while((pos = version1.find(delimiter)) != string::npos){
            v1.push_back(version1.substr(0, pos));
            version1.erase(0, pos + 1);
        }
        v1.push_back(version1);
        while((pos = version2.find(delimiter)) != string::npos){
            v2.push_back(version2.substr(0, pos));
            version2.erase(0, pos + 1);
        }
        v2.push_back(version2);

        int len = max(v1.size(), v2.size());
        vector<int> compare1(len, 0), compare2(len, 0);
        int i = 0;
        for (auto s : v1) compare1[i++] = stoi(s);
        i = 0;
        for (auto s : v2) compare2[i++] = stoi(s);

        for (int i = 0; i < len; i++){
            if (compare1.at(i) == compare2.at(i)) continue;
            else if (compare1.at(i) > compare2.at(i)) return 1;
            else return -1;
        }
        return 0;
    }
};

int main(){
    string version1, version2;
    cin >> version1 >> version2;
    Solution S;
    cout << S.compareVersion(version1, version2) << endl;
    return 0;
}


// reference answer
// class Solution {
// public:
//     int compareVersion(string version1, string version2) {   
//         int i = 0, j = 0, n1 = version1.size(), n2 = version2.size(), num1 = 0, num2 = 0; 
//         while(i<n1 || j<n2)
//         {
//             while(i<n1 && version1[i]!='.')
//             {
//                 num1 = num1*10+(version1[i]-'0');
//                 i++;
//             }
//             while(j<n2 && version2[j]!='.')
//             {
//                 num2 = num2*10+(version2[j]-'0');
//                 j++;
//             }
//             if(num1>num2)
//             {
//                 return 1;
//             }
//             if(num1 < num2) 
//             {
//                 return -1;
//             }
//             i++;
//             j++;
//             num1 = 0;
//             num2 = 0;
//         }
//         return 0; 
//     }
// };