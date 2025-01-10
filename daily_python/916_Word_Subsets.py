import sys
import os
from typing import List

class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        def count(s):
            cnt = [0] * 26
            for c in s:
                cnt[ord(c) - ord('a')] += 1
            return cnt
        universal = [0] * 26
        for s in words2:
            for i, c in enumerate(count(s)):
                universal[i] = max(universal[i], c)
        ans = []
        for s in words1:
            if all(w1 >= w2 for w1, w2 in zip(count(s), universal)):
                ans.append(s)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            words1 = list(lines[0].split('=')[1].strip()[2:-3].split('","'))
            words2 = list(lines[1].split('=')[1].strip()[2:-3].split('","'))
            dataset.append((words1, words2))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for words1, words2 in dataset:
        results.append(solution.wordSubsets(words1, words2))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')