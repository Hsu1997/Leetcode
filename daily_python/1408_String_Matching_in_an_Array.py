import os
import sys
from typing import List

class Solution:
    def constructlps(self, pattern):
        n = len(pattern)
        lps = [0] * n
        l = 0
        for i in range(1, n):
            while l > 0 and pattern[i] != pattern[l]:
                l = lps[l-1]
            if pattern[l] == pattern[i]:
                l += 1
            lps[i] = l
        return lps
    
    def kmp(self, pattern, content, lps):
        n = len(content)
        m = len(pattern)
        j = 0
        for i in range(n):
            while j > 0 and content[i] != pattern[j]:
                j = lps[j-1]
            if pattern[j] == content[i]:
                j += 1
            if j == m:
                return True
                j = lps[j-1]
        return False

    def stringMatching(self, words: List[str]) -> List[str]:
        n = len(words)
        ans = []
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                lps = self.constructlps(words[i])
                if self.kmp(words[i], words[j], lps):
                    ans.append(words[i])
                    break
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[2:-3].split('","')
            dataset.append(s)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for words in dataset:
        results.append(solution.stringMatching(words))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')