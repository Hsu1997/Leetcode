import os
import sys
from typing import List

class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        restrictions.append([1,0])
        restrictions.sort()
        if restrictions[-1][0] != n:
            restrictions.append([n, n - 1])
        r = len(restrictions)
        ans = 0
        for i in range(r - 2, -1, -1):
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + restrictions[i+1][0] - restrictions[i][0])
        for i in range(1, r):
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + restrictions[i][0] - restrictions[i-1][0])
            ans = max(ans, (restrictions[i-1][1] + restrictions[i][1] + (restrictions[i][0] - restrictions[i-1][0])) // 2)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            restrictions = [list(map(int, restriction.split(','))) for restriction in lines[1].split('=')[1].strip()[2:-3].split('},{') if restriction]
            dataset.append((n, restrictions))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, restrictions in dataset:
        results.append(solution.maxBuilding(n, restrictions))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')