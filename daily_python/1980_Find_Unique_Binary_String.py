import os
import sys
from typing import List

class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums)
        ans = []
        for i in range(n):
            if nums[i][i] == '0':
                ans.append('1')
            else:
                ans.append('0')
        return "".join(ans)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = lines[0].split('=')[1].strip()[2:-3].split('","')
            dataset.append(nums)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums in dataset:
        results.append(solution.findDifferentBinaryString(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')