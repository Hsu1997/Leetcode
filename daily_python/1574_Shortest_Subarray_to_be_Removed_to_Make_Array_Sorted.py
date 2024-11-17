import os
import sys
from typing import List

class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        right = n - 1
        while right > 0 and arr[right-1] <= arr[right]:
            right -= 1
        ans = right
        left = 0
        while left < right and (left == 0 or arr[left-1] <= arr[left]):
            while right < n and arr[left] > arr[right]:
                right += 1
            ans = min(ans, right - left - 1)
            left += 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arr = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
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
        results.append(solution.findLengthOfShortestSubarray(arr))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')