import os
import sys
from typing import List

class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        if not arr:
            return None
        nums = sorted(arr)
        dict = {}
        index = 0
        for i, num in enumerate(nums):
            if i == 0 or num != nums[i-1]:
                index += 1
            dict[num] = index
        ans = []
        for i in arr:
            ans.append(dict[i])
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            data = lines[0].split('=')[1].strip()[1:-2]
            arr = list(map(int, data.split(','))) if data else None
            dataset.append(arr)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arr in dataset:
        results.append(solution.arrayRankTransform(arr))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
