import os
import sys
from typing import List

class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        total = sum(skill)
        if total % (n // 2) != 0:
            return -1
        target = total // (n // 2)
        count = {}
        for i in skill:
            if i not in count:
                count[i] = 1
            else:
                count[i] += 1
        ans = 0
        for i in skill:
            if count[i] > 0:
                count[i] -= 1
                if (target - i) not in count or count[target - i] <= 0:
                    return -1
                count[target - i] -= 1
                ans += i * (target - i)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            skill = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(skill)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for skill in dataset:
        results.append(solution.dividePlayers(skill))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')