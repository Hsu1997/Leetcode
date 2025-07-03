import os
import sys
from typing import List

class Solution:
    def mul(self, s: List[List[int]], t: List[List[int]]) -> List[List[int]]:
        mod = 10 ** 9 + 7
        m = len(s)
        n = len(s[0])
        k = len(t[0])
        if len(t) != n:
            return []
        ans = [[0] * k for _ in range(m)]
        for i in range(m):
            for j in range(k):
                for l in range(n):
                    ans[i][j] = (ans[i][j] + (s[i][l] * t[l][j])) % mod
        return ans
    
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        mod = 10 ** 9 + 7
        # [1x26] * ([26 * 26] ^ t) = [1 * 26]
        init = [[0] * 26]
        for c in s:
            init[0][ord(c) - ord('a')] += 1
        trans = [[0] * 26 for _ in range(26)]
        for i in range(26):
            for j in range(1, nums[i] + 1):
                trans[i][(i + j) % 26] = 1
        res = [[0] * 26 for _ in range(26)]
        for i in range(26):
            res[i][i] = 1
        while t:
            if t % 2 == 1:
                res = self.mul(res, trans)
            trans = self.mul(trans, trans)
            t //= 2
        ending = self.mul(init, res)[0]
        ans = 0
        for cnt in ending:
            ans = (ans + cnt) % mod
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            t = int(lines[1].split('=')[1].strip()[:-1])
            nums = list(map(int, lines[2].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((s, t, nums))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, t, nums in dataset:
        results.append(solution.lengthAfterTransformations(s, t, nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')