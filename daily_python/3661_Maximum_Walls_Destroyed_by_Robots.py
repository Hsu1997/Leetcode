import os
import sys
from typing import List

class Solution:
    def maxWalls(self, robots: List[int], distance: List[int], walls: List[int]) -> int:
        n, m = len(robots), len(walls)
        robotToDistance = {}
        for i in range(n):
            robotToDistance[robots[i]] = distance[i]
        robots.sort()
        walls.sort()
        prevLeft, prevRight = 0, 0
        upperboundPtr, lowerboundPtr = 0, 0
        
        for i in range(n):
            currRobot = robots[i]
            currDis = robotToDistance[currRobot]
            currLeft, currRight = 0, 0
            # Shooting Left
            # Previous shooting left
            while upperboundPtr < m and walls[upperboundPtr] <= currRobot:
                upperboundPtr += 1
            leftBorder = currRobot - currDis if i == 0 else max(robots[i-1] + 1, currRobot - currDis)
            tempLowerboundPtr = lowerboundPtr
            while lowerboundPtr < m and walls[lowerboundPtr] < leftBorder:
                lowerboundPtr += 1
            currLeft = prevLeft + upperboundPtr - lowerboundPtr
            # Previous shooting right
            prevShootingRightBorder = currRobot - currDis if i == 0 else max(currRobot - currDis, min(robots[i-1] + robotToDistance[robots[i-1]] + 1, currRobot))
            lowerboundPtr = tempLowerboundPtr
            while lowerboundPtr < m and walls[lowerboundPtr] < prevShootingRightBorder:
                lowerboundPtr += 1
            currLeft = max(currLeft, prevRight + upperboundPtr - lowerboundPtr)

            # Shooting Right
            rightBorder = currRobot + currDis if i == n - 1 else min(currRobot + currDis, robots[i+1] - 1)
            while upperboundPtr < m and walls[upperboundPtr] <= rightBorder:
                upperboundPtr += 1
            while lowerboundPtr < m and walls[lowerboundPtr] < currRobot:
                lowerboundPtr += 1
            currRight = max(prevLeft, prevRight) + (upperboundPtr - lowerboundPtr)
            prevLeft, prevRight = currLeft, currRight
        return max(prevLeft, prevRight)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            robots = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            distance = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(','))) 
            walls = list(map(int, lines[2].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((robots, distance, walls))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for robots, distance, walls in dataset:
        results.append(solution.maxWalls(robots, distance, walls))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')