import os
import sys

class Solution:
    def count_one(self, i):
        count = 0
        while i:
            if i % 2 == 1:
                count += 1
            i //= 2
        return count
    
    def minBitFlips(self, start: int, goal: int) -> int:
        return self.count_one(start ^ goal)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            start = int(lines[0].split('=')[1].strip()[:-1])
            goal = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((start, goal))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for start, goal in dataset:
        results.append(solution.minBitFlips(start, goal))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')