#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string,string> en_map, de_map;
    string url_lib = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    string getcode(){
        string code;
        for (int i = 0; i < 6; i++){
            code += url_lib[rand()%62];
        }
        // cout << code << endl;
        return code;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (de_map.find(longUrl) != de_map.end()) return de_map[longUrl];
        string code = getcode();
        while(en_map.find(code) != en_map.end()) code = getcode();
        en_map["http://tinyurl.com/" + code] = longUrl;
        de_map[longUrl] = "http://tinyurl.com/" + code;
        // cout << en_map["http://tinyurl.com/" + code] << endl;
        // cout << de_map[longUrl] << endl;
        return "http://tinyurl.com/" + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        // cout << shortUrl << endl;
        return en_map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(){
    string url = "https://leetcode.com/problems/design-tinyurl";
    Solution S;
    cout << S.decode(S.encode(url)) << endl;
    return 0;
}