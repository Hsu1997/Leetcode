import os
import sys
from typing import List

class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        n = len(positions)
        index = [x for x in range(n)]
        index.sort(key = lambda x : positions[x])
        sta = []
        for i in range(n):
            curr = index[i]
            if directions[curr] == 'L':
                while sta and healths[curr] > 0:
                    if healths[curr] >= healths[sta[-1]]:
                        if healths[curr] == healths[sta[-1]]:
                            healths[curr] = 0
                        healths[sta[-1]] = 0
                        sta.pop()
                        healths[curr] -= 1
                    else:
                        healths[curr] = 0
                        healths[sta[-1]] -= 1
            else:
                sta.append(curr)
        ans = [healths[x] for x in range(n) if healths[x] > 0]
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            positions = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            healths = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            directions = lines[2].split('=')[1].strip()[1:-2]
            dataset.append((positions, healths, directions))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for positions, healths, directions in dataset:
        results.append(solution.survivedRobotsHealths(positions, healths, directions))
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : {result}')