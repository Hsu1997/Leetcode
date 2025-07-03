import os
import sys
from typing import List

class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(words)
        ans = []
        for i in range(n):
            if i == 0 or groups[i] != groups[i-1]:
                ans.append(words[i])
        return ans

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
        results.append(solution.getLongestSubsequence(words, groups))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')