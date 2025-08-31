import os
import sys
from typing import List, Tuple

class Solution:
    @staticmethod
    def pos(idx: int) -> List[int]:
        return [idx // 9, idx % 9]
    @staticmethod
    def block(i: int, j: int) -> int:
        return i // 3 * 3 + j // 3
    
    def solveSudoku(self, board: List[List[str]]) -> None:
        self.rows = [0] * 9
        self.cols = [0] * 9
        self.squares = [0] * 9
        self.blanks = []
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    self.blanks.append((i, j))
                else:
                    k = ord(board[i][j]) - ord('1')
                    b = self.block(i, j)
                    self.rows[i] |= (1 << k)
                    self.cols[j] |= (1 << k)
                    self.squares[b] |= (1 << k)
        self.bfs(board, 0)
        return
    
    def count_candidate(self, i: int, j: int) -> Tuple[int, int]:
        used = self.rows[i] | self.cols[j] | self.squares[self.block(i, j)]
        candidate = (~used) & ((1 << 9) - 1) 
        cnt, t = 0, candidate
        while t:
            t -= (t & -t)
            cnt += 1
        return candidate, cnt
        
    def bfs(self, board: List[List[str]], idx: int) -> bool:
        if idx == len(self.blanks):
            return True
        best = idx
        best_candidate = 0
        min_choices = 10
        
        for t in range(idx, len(self.blanks)):
            i, j = self.blanks[t]
            candidate, cnt = self.count_candidate(i, j)
            if cnt < min_choices:
                best = t
                best_candidate = candidate
                min_choices = cnt
                if cnt == 1:
                    break
        
        if best != idx:
            self.blanks[idx], self.blanks[best] = self.blanks[best], self.blanks[idx]
        i, j = self.blanks[idx]
        candidate = best_candidate
        b = self.block(i, j)

        while candidate:
            bit = candidate & (-candidate)
            candidate -= bit
            k = bit.bit_length() - 1

            self.rows[i] |= bit
            self.cols[j] |= bit
            self.squares[b] |= bit
            board[i][j] = chr(ord('1') + k)

            if self.bfs(board, idx + 1):
                return True

            board[i][j] = '.'
            self.rows[i] &= ~bit
            self.cols[j] &= ~bit
            self.squares[b] &= ~bit
        return False
            
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
        solution.solveSudoku(board)
        results.append(board)
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
