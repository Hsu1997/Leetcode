import sys
import os
from typing import List
from collections import deque

class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        ladder = [0] * (n * n + 1)
        for row in range(n-1, -1, -1):
            for col in range(n):
                row_count = n - 1 - row
                col_count = col + 1 if row_count % 2 == 0 else n - col
                index = row_count * n + col_count
                if board[row][col] == -1:
                    ladder[index] = index
                else:
                    ladder[index] = board[row][col]
        visited = [-1] * (n * n + 1)
        visited[1] = 0
        que = deque([1])
        while que:
            curr = que.popleft()
            for i in range(1, 7):
                next = ladder[curr + i]
                if next == n * n:
                    return visited[curr] + 1
                if visited[next] != -1:
                    continue
                visited[next] = visited[curr] + 1
                que.append(next)
        return -1

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            board = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(board)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for board in dataset:
        results.append(solution.snakesAndLadders(board))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')