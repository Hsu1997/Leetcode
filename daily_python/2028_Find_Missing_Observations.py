import os
import sys
from typing import List

class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        total = mean * (m + n)
        observation = sum(rolls)
        missing = total - observation
        if missing < n or missing > 6 * n:
            return []
        ans = [missing // n] * n
        for index in range(missing % n):
            ans[index] += 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            rolls = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            mean = int(lines[1].split('=')[1].strip()[:-1])
            n = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((rolls, mean, n))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for rolls, mean, n in dataset:
        results.append(solution.missingRolls(rolls, mean, n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')