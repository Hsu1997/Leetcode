import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        r = defaultdict(int)
        ans = 0
        for i in answers:
            if i == 0:
                ans += 1
            else:
                if r[i] == 0:
                    ans += i + 1
                    r[i] = i
                else:
                    r[i] -= 1
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            answers = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(answers)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for answers in dataset:
        results.append(solution.numRabbits(answers))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')