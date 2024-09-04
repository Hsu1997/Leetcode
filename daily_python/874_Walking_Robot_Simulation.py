import os
import sys
from typing import List

class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        ans = 0
        obs = set((o[0], o[1]) for o in obstacles)
        x, y = 0, 0
        d = [[0,1],[1,0],[0,-1],[-1,0]]
        dir = 0
        for command in commands:
            if command == -1:
                dir = (dir + 1) % 4
            elif command == -2:
                dir = (dir + 3) % 4
            else:
                for _ in range(command):
                    nx = x + d[dir][0]
                    ny = y + d[dir][1]
                    if (nx, ny) not in obs:
                        x, y = nx, ny
                        ans = max(ans, x * x + y * y)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            commands = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            obstacle = lines[1].split('=')[1].strip()[2:-3].split('},{')
            obstacles = [list(map(int, o.split(','))) for o in obstacle] if obstacle != [''] else []
            dataset.append((commands, obstacles))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for commands, obstacles in dataset:
        results.append(solution.robotSim(commands, obstacles))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')