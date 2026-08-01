import os
import sys
from typing import List

class Solution:
    def dp(self, s: int, e: int, nums: List[int]) -> int:
        if s > e:
            return 0
        if self.memo[s][e] != float('-inf'):
            return self.memo[s][e]
        self.memo[s][e] = max(nums[s] - self.dp(s + 1, e, nums), nums[e] - self.dp(s, e - 1, nums))
        return self.memo[s][e]
    
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        self.memo = [[float('-inf')] * n for _ in range(n)]
        self.dp(0, n - 1, nums)
        return self.memo[0][n-1] >= 0
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(nums)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums in dataset:
        results.append(solution.predictTheWinner(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')