import os
import sys
from typing import List

class Solution:
    def check_valid(self, quantities: List[int], amount: int, n: int):
        ans = 0
        for i in quantities:
            ans += i // amount + (i % amount > 0)
            if ans > n:
                return False
        return True
    
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        q = len(quantities)
        if q > n:
            return -1
        if q == n:
            return max(quantities)
        total = sum(quantities)
        left = total // n + (total % n > 0)
        right = max(quantities)
        ans = right
        while left <= right:
            mid = (left + right) // 2
            if self.check_valid(quantities, mid, n):
                ans = min(ans, mid)
                right = mid - 1
            else:
                left = mid + 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            quantities = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((n, quantities))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, quantities in dataset:
        results.append(solution.minimizedMaximum(n, quantities))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')