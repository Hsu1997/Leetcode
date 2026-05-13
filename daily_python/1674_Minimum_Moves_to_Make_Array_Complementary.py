import os
import sys
from typing import List

class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        c = [0] * (limit * 2 + 2)
        for i in range(n // 2):
            a = min(nums[i], nums[n-1-i])
            b = max(nums[i], nums[n-1-i])
            c[a+b] -= 1
            c[a+b+1] += 1
            c[a+1] -= 1
            c[b+limit+1] +=1
        m = 0
        acc = 0
        for i in c:
            acc += i
            m = min(m, acc)
        return n + m
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            limit = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, limit))
    return dataset

if __name__ == "__main__":
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, limit in dataset:
        results.append(solution.minMoves(nums, limit))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')