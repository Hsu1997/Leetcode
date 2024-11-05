import os
import sys
from typing import List

class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot.sort()
        factory.sort()
        factory = [f for f in factory if f[1] > 0]
        r = len(robot)
        f = len(factory)
        prev = [float('inf')] * r
        curr = [float('inf')] * r
        prev[0] = abs(robot[0] - factory[0][0])
        for j in range(1, min(r,factory[0][1])):
            prev[j] = prev[j-1] + abs(robot[j] - factory[0][0])
        for i in range(1, f):
            for j in range(r):
                curr[j] = prev[j]
                limit = factory[i][1]
                acc = 0
                for k in range(limit):
                    if j - k >= 0:
                        acc += abs(factory[i][0] - robot[j-k])
                        if j - k - 1 < 0:
                            curr[j] = min(curr[j], acc)
                        else:
                            if prev[j-k-1] == float('inf'):
                                continue
                            curr[j] = min(curr[j], acc + prev[j-k-1])
                if curr[j] == float('inf'):
                    break
            prev = curr.copy()
        return prev[-1]
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            robot = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            factory = [list(map(int, i.split(','))) for i in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((robot, factory))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for robot, factory in dataset:
        results.append(solution.minimumTotalDistance(robot, factory))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')