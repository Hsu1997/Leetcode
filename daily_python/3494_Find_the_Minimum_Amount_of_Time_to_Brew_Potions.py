import os
import sys
from typing import List

class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        n = len(skill)
        m = len(mana)
        time = [0] * n
        for k in mana:
            time[0] += skill[0] * k
            for i in range(1, n):
                time[i] = max(time[i-1], time[i]) + skill[i] * k
            for i in range(n - 2, -1, -1):
                time[i] = time[i+1] - skill[i+1] * k
        return time[-1]
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            skill = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            mana = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((skill, mana))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for skill, mana in dataset:
        results.append(solution.minTime(skill, mana))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')