import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        ans = 0
        count = defaultdict(int)
        for dominoe in dominoes:
            curr = min(dominoe[0], dominoe[1]) * 10 + max(dominoe[0], dominoe[1])
            ans += count[curr]
            count[curr] += 1
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            dominoes = [list(map(int, dominoe.split(','))) for dominoe in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(dominoes)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for dominoes in dataset:
        results.append(solution.numEquivDominoPairs(dominoes))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')