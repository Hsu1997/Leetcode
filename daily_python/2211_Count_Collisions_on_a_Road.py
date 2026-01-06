import os
import sys

class Solution:
    def countCollisions(self, directions: str) -> int:
        n = len(directions)
        l, r = 0, n - 1
        while l < n and directions[l] == 'L':
            l += 1
        while r >= 0 and directions[r] == 'R':
            r -= 1
        ans = 0
        for i in range(l, r + 1):
            if directions[i] != 'S':
                ans += 1
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            directions = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(directions)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for directions in dataset:
        results.append(solution.countCollisions(directions))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')