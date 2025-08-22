import os
import sys
from typing import List

class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        height = [0] * n
        ans = 0
        for row in range(m):
            height = [0 if b == 0 else h + 1 for (b, h) in zip(mat[row], height)]
            # (col, acc, height)
            stack = [(-1, 0, -1)]
            for col in range(n):
                curr_height = height[col]
                while curr_height <= stack[-1][2]:
                    stack.pop()
                prev_col = stack[-1][0]
                prev_acc = stack[-1][1]
                curr_acc = (col - prev_col) * curr_height + prev_acc
                stack.append((col, curr_acc, curr_height))
                ans += curr_acc
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            mat = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(mat)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for mat in dataset:
        results.append(solution.numSubmat(mat))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')