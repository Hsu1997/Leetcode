import os
import sys
from typing import List

class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        m = len(boxGrid)
        n = len(boxGrid[0])
        ans = [['.'] * m for _ in range(n)]
        for i in range(m):
            for j in range(n):
                ans[j][i] = boxGrid[i][j]
        for row in ans:
            row.reverse()
        for j in range(m):
            stone = 0
            for i in range(n):
                if ans[i][j] == '#':
                    ans[i][j] = '.'
                    stone += 1
                elif ans[i][j] == '*':
                    pos = i-1
                    while stone:
                        ans[pos][j] = '#'
                        stone -= 1
                        pos -= 1
                else:
                    continue
            pos = n-1
            while stone:
                ans[pos][j] = '#'
                stone -= 1
                pos -= 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            boxGrid = [list(i.strip('\'').split("','")) for i in lines[0].split('=')[1].strip()[3:-4].split('},{')]
            dataset.append(boxGrid)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for boxGrid in dataset:
        results.append(solution.rotateTheBox(boxGrid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')