import os
import sys
from typing import List

class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        if k == 0:
            return 0
        n = len(s)
        if n < k * 3:
            return -1
        count = [0] * 3
        for c in s:
            count[ord(c)-ord('a')] += 1
        for c in count:
            if c < k:
                return -1
        ans = n
        left = 0
        for right in range(n):
            count[ord(s[right]) - ord('a')] -= 1
            while left <= right and (count[0] < k or count[1] < k or count[2] < k):
                count[ord(s[left]) - ord('a')] += 1
                left += 1
            ans = min(ans, n - (right - left + 1))
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((s, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, k in dataset:
        results.append(solution.takeCharacters(s, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')