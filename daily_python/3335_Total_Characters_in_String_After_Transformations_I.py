import os
import sys
from typing import List

class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        mod = int(1e9 + 7)
        count = [0] * 26
        for c in s:
            count[ord(c) - ord('a')] += 1
        z_pos = 25
        for i in range(t):
            count[(z_pos + 1) % 26] = (count[(z_pos + 1) % 26] + count[z_pos]) % mod
            z_pos = (z_pos + 25) % 26
        ans = 0
        for i in count:
            ans = (ans + i) % mod
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
            dataset.append((s, t))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, t in dataset:
        results.append(solution.lengthAfterTransformations(s, t))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')