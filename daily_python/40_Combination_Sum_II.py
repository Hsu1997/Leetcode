import sys
import os
from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        self.ans = []
        self.target = target
        self.candidates = candidates
        self.n = len(candidates)
        self.helper([], 0, 0)
        return self.ans

    def helper(self, temp: List[int], acc: int, i: int):
        if acc == self.target:
            self.ans.append(temp)
            return
        if acc > self.target:
            return
        for next in range(i, self.n, 1):
            if next == i or self.candidates[next] != self.candidates[next-1]:
                self.helper(temp + [self.candidates[next]], acc + self.candidates[next], next + 1)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            candidate = list(map(int, lines[0].split('=')[1][2:-2].split(',')))
            target = int(lines[1].split('=')[1].strip()[0])
            dataset.append((candidate, target))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for candidates, target in dataset:
        results.append(solution.combinationSum2(candidates, target))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')