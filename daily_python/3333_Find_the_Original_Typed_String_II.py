import os
import sys
from typing import List

class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        freq = []
        word += "."
        n = len(word)
        l = 1
        mod = 10 ** 9 + 7
        for i in range(1, n):
            if word[i] == word[i-1]:
                l += 1
            else:
                freq.append(l)
                l = 1
        ans = 1
        for f in freq:
            ans = ans * f % mod
        if len(freq) >= k:
            return ans
        presum = [1] * k
        for f in freq:
            curr = [0] * k
            for i in range(1, k):
                curr[i] = presum[i-1]
                if i - 1 - f >= 0:
                    curr[i] -= presum[i - 1 - f]
                    if curr[i] < 0:
                        curr[i] += mod
            presum[0] = curr[0]
            for i in range(1, k):
                presum[i] = presum[i-1] + curr[i] % mod
        ans = (ans - presum[k - 1] + mod) % mod
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
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
        results.append(solution.possibleStringCount(word, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')