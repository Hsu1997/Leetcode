import os
import sys
from typing import List

class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:
        m, n = len(word1), len(word2)
        right = [-1] * n
        i = m - 1
        for j in range(n - 1, -1, -1):
            while i >= 0 and word1[i] != word2[j]:
                i -= 1
            if i < 0:
                break
            right[j] = i
            i -= 1
        ans = []
        changed = False
        j = 0
        for i in range(m):
            if word1[i] == word2[j]:
                ans.append(i)
                j += 1
            else:
                if not changed and (j == n - 1 or i < right[j + 1]):
                    changed = True
                    ans.append(i)
                    j += 1
            if j == n:
                return ans
        return []
        
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            word1 = lines[0].split('=')[1].strip()[1:-2]
            word2 = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((word1, word2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for word1, word2 in dataset:
        results.append(solution.validSequence(word1, word2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    