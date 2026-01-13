import os
import sys
from typing import List, Dict

class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        cnt = {}
        total = 0.0
        for x, y, l in squares:
            start = y
            end = y + l
            l = float(l)
            cnt[start] = cnt.get(start, 0.0) + l
            cnt[end] = cnt.get(end, 0.0) - l
            total += l * l
        total /= 2.0
        acc = 0.0
        preY = 0
        for y, l in sorted(cnt.items()):
            dy = y - preY
            area = dy * acc
            if area >= total:
                return preY + total / acc
            total -= area
            acc += l
            preY = y
        return preY + total / acc

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            squares = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(squares)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for squares in dataset:
        results.append(solution.separateSquares(squares))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')