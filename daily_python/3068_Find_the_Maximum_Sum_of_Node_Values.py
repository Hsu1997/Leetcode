import os
import sys
from typing import List

class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        ans = 0
        odd = 0
        m = float('inf')
        for temp in nums:
            ori = temp
            trans = temp ^ k
            if trans > ori:
                odd ^= 1
            m = min(m, max(ori, trans) - min(ori, trans))
            ans += max(ori, trans)
        if odd:
            ans -= m
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            edges = [list(map(int, edge.split(','))) for edge in lines[2].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((nums, k, edges))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, k, edges in dataset:
        results.append(solution.maximumValueSum(nums, k, edges))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')