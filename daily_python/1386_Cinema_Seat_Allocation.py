import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        m = defaultdict(int)
        for seat in reservedSeats:
            if 2 <= seat[1] <= 9:
                m[seat[0]] |= (1 << (seat[1] - 2))
        ans = (n - len(m)) * 2
        for b in m.values():
            if b & (15)  == 0 or b & (15 << 2) == 0 or b & (15 << 4) == 0:
                ans += 1
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            reservedSeats = [list(map(int, r.split(','))) for r in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((n, reservedSeats))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, reservedSeats in dataset:
        results.append(solution.maxNumberOfFamilies(n, reservedSeats))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
