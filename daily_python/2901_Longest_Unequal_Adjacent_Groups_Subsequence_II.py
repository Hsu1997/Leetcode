import os
import sys
from typing import List

class Solution:
    def check(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        diff = 0
        for c1, c2 in zip(s1, s2):
            if c1 != c2:
                diff += 1
        return diff == 1

    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(words)
        l = [1] * n
        prev = [-1] * n
        maxidx = 0
        for i in range(1, n):
            for j in range(i):
                if groups[i] != groups[j] and self.check(words[i], words[j]) and l[j] + 1 > l[i]:
                    l[i] = l[j] + 1
                    prev[i] = j
            if l[i] > l[maxidx]:
                maxidx = i
        ans = []
        while maxidx != -1:
            ans.append(words[maxidx])
            maxidx = prev[maxidx]
        return ans[::-1]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            words = list(lines[0].split('=')[1].strip()[2:-3].split('","'))
            groups = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((words, groups))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for words, groups in dataset:
        results.append(solution.getWordsInLongestSubsequence(words, groups))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')