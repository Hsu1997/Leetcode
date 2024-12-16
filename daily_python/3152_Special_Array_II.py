import os
import sys
from typing import List

class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(nums)
        q = len(queries)
        acc_error = [0] * n
        for i in range(1, n):
            if nums[i-1] % 2 == nums[i] % 2:
                acc_error[i] = acc_error[i-1] + 1
            else:
                acc_error[i] = acc_error[i-1]
        ans = [0] * q
        for i in range(q):
            start = queries[i][0]
            end = queries[i][1]
            ans[i] = acc_error[start] == acc_error[end]
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            queries = [list(map(int, i.split(','))) for i in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((nums, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, queries in dataset:
        results.append(solution.isArraySpecial(nums, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
