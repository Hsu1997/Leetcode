import os
import sys
from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = len(board)
        row = [0] * n
        col = [0] * n
        square = [0] * n
        for i in range(n):
            for j in range(n):
                if board[i][j] == '.':
                    continue
                curr = ord(board[i][j]) - ord('0')
                if row[i] & (1 << curr):
                    return False
                row[i] |= (1 << curr)
                if col[j] & (1 << curr):
                    return False
                col[j] |= (1 << curr)
                idx = (i // 3) * 3 + (j // 3)
                if square[idx] & (1 << curr):
                    return False
                square[idx] |= (1 << curr)
        return True

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            board = [row.split("','") for row in lines[0].split('=')[1].strip()[3:-4].split("'},{'")]
            dataset.append(board)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for board in dataset:
        results.append(solution.isValidSudoku(board))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
