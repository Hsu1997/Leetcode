import os
import sys
from typing import List

class SegmentTree:
    def __init__(self, x: List[int]):
        self.x = x
        self.n = len(x) - 1
        self.cnt = [0] * (4 * self.n)
        self.covered = [0] * (4 * self.n)
    
    def update(self, qleft, qright, qval):
        self.modify(qleft, qright, qval, 0, self.n - 1, 0)
    
    def query(self):
        return self.covered[0]
    
    def modify(self, qleft, qright, qval, leftInterval, rightInterval, nodeidx):
        if qleft >= self.x[rightInterval + 1] or qright <= self.x[leftInterval]:
            return
        if qleft <= self.x[leftInterval] and self.x[rightInterval + 1] <= qright:
            self.cnt[nodeidx] += qval
        else:
            mid = (leftInterval + rightInterval) // 2
            self.modify(qleft, qright, qval, leftInterval, mid, nodeidx * 2 + 1)
            self.modify(qleft, qright, qval, mid + 1, rightInterval, nodeidx * 2 + 2)
        
        if self.cnt[nodeidx] > 0:
            self.covered[nodeidx] = self.x[rightInterval + 1] - self.x[leftInterval]
        else:
            if leftInterval == rightInterval:
                self.covered[nodeidx] = 0
            else:
                self.covered[nodeidx] = self.covered[nodeidx * 2 + 1] + self.covered[nodeidx * 2 + 2]
            
class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        events = []
        xs = set()
        for x, y, l in squares:
            events.append((y, 1, x, x + l))
            events.append((y + l, -1, x, x + l))
            xs.add(x)
            xs.add(x + l)
        events.sort()
        ST = SegmentTree(sorted(xs))
        yPos = []
        width = []
        area = []
        totalArea = 0
        preY = events[0][0]
        for y, d, s, e in events:
            if y != preY:
                l = ST.query()
                yPos.append(preY)
                width.append(l)
                area.append(totalArea)
                totalArea += (y - preY) * l
            ST.update(s, e, d)
            preY = y
        
        idx = 0
        while idx < len(area) and area[idx] < totalArea / 2:
            idx += 1
        idx -= 1
        return yPos[idx] + (totalArea / 2 - area[idx]) / width[idx]

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