import os
import sys
from typing import List

class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        self.n = n
        self.result = [0] * (2 * n - 1)
        self.used = [False] * (n + 1)
        self.track(0)
        return self.result

    def track(self, pos):
        if pos == self.n * 2 - 1:
            return True
        if self.result[pos] != 0:
            return self.track(pos + 1)
        for num in range(self.n, 1, -1):
            if self.used[num] or pos + num > len(self.result) - 1 or self.result[pos + num] != 0:
                continue
            self.result[pos] = num
            self.result[pos + num] = num
            self.used[num] = True
            if self.track(pos + 1):
                return True
            self.result[pos] = 0
            self.result[pos + num] = 0
            self.used[num] = False
        if not self.used[1] and self.result[pos] == 0:
            self.result[pos] = 1
            self.used[1] = True
            if self.track(pos+1):
                return True
            self.result[pos] = 0
            self.used[1] = False
        return False
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            dataset.append(n)
    return dataset

if __name__ == "__main__":
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n in dataset:
        results.append(solution.constructDistancedSequence(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')