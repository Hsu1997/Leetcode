import os
import sys
from typing import List
from collections import deque

class Solution:
    def swap(self, state, i, j):
        state = list(state)
        state[i], state[j] = state[j], state[i]
        return "".join(state)
    
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        target = "123450"
        start = []
        for i in range(len(board)):
            for j in range(len(board[0])):
                start.append(str(board[i][j]))
        start_state = "".join(start)
        que = deque([start_state])
        visited = set()
        visited.add(start_state)
        move = 0
        dir = [[1, 3],[0, 2, 4],[1, 5],[0, 4],[1, 3, 5],[2, 4]]

        while que:
            for _ in range(len(que)):
                curr = que.popleft()
                if curr == target:
                    return move
                zero_pos = curr.index("0")
                for new_pos in dir[zero_pos]:
                    next = self.swap(curr, zero_pos, new_pos)
                    if next in visited:
                        continue
                    visited.add(next)
                    que.append(next)
            move += 1
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
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for board in dataset:
        results.append(solution.slidingPuzzle(board))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')