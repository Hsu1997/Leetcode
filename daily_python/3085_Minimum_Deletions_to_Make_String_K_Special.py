import os
import sys
from typing import List

class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        count = [0] * 26
        for c in word:
            count[ord(c) - ord('a')] += 1
        res = []
        for c in count:
            if c:
                res.append(c)
        res = sorted(res)
        n = len(res)
        acc = 0
        ans = 1000000
        for i in range(n):
            curr = acc
            for j in range(i+1, n):
                curr += max(0, res[j] - res[i] - k)
            ans = min(ans, curr)
            acc += res[i]
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            word = lines[0].split('=')[1].strip()[1:-2]
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((word, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for word, k in dataset:
        results.append(solution.minimumDeletions(word, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')