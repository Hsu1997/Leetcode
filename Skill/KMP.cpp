#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 函數：構建LPS陣列
vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0; // 前綴長度

    for (int i = 1; i < m; i++) { // i++ 在for迴圈控制部分
        while (len > 0 && pattern[i] != pattern[len]) {
            len = lps[len - 1]; // 根據LPS陣列回溯
        }
        if (pattern[i] == pattern[len]) {
            len++; // 匹配時增加len
        }
        lps[i] = len; // 更新lps[i]
    }
    return lps;
}

// KMP搜索演算法
void KMPSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPSArray(pattern);

    int j = 0; // 模式指針

    for (int i = 0; i < n; i++) { // i++ 在for迴圈控制部分
        while (j > 0 && pattern[j] != text[i]) {
            j = lps[j - 1]; // 根據LPS陣列回溯
        }
        
        if (pattern[j] == text[i]) {
            j++; // 匹配時增加j
        }

        if (j == m) {
            cout << "找到模式，起始索引：" << (i - j + 1) << endl; // 計算起始索引
            j = lps[j - 1]; // 根據LPS陣列回溯
        }
    }
}

int main() {
    // string text = "ABABDABABCABABDABABCABAB";
    // string pattern = "ABABCABAB";
    string text = "ABABABABDABABCABABDABABCABAB";
    string pattern = "ABAB";

    KMPSearch(text, pattern);

    return 0;
}