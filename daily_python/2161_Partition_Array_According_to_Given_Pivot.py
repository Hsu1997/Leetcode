import sys
import os
from typing import List

class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        n = len(nums)
        less = 0
        greater = 0
        for num in nums:
            if num > pivot:
                greater += 1
        ans = [pivot] * n
        greater = n - greater
        for num in nums:
            if num < pivot:
                ans[less] = num
                less += 1
            if num > pivot:
                ans[greater] = num
                greater += 1
        return ans
    
def readData(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            pivot = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, pivot))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readData(filename)
    results = []
    solution = Solution()
    for nums, pivot in dataset:
        results.append(solution.pivotArray(nums, pivot))
    for index, result in enumerate(results):
        print(f'dataset {index+1} : {result}')
