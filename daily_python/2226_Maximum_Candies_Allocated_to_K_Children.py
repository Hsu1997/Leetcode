import os
import sys
from typing import List

class Solution:
    def valid_allocation(self, candies: List[int], k: int, amount: int) -> bool:
        piles = 0
        for candy in candies:
            piles += candy // amount
            if piles >= k:
                return True
        return False
    
    def maximumCandies(self, candies: List[int], k: int) -> int:
        left = 1
        right = sum(candies) // k
        ans = 0
        while left <= right:
            mid = (left + right) // 2
            if self.valid_allocation(candies, k, mid):
                ans = max(ans, mid)
                left = mid + 1
            else:
                right = mid - 1
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            candies = list(map(int,lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((candies, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for candies, k in dataset:
        results.append(solution.maximumCandies(candies, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')