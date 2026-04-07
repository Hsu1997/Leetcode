import os
import sys
from typing import List

class Robot:
    def __init__(self, width: int, height: int):
        self.w = width
        self.h = height
        self.cycle = 2 * (self.w + self.h - 2)
        self.acc = 0

    def step(self, num: int) -> None:
        self.acc += num

    def getPos(self) -> List[int]:
        d = self.acc % self.cycle
        if d < self.w:
            return [d, 0]
        elif d < self.w - 1 + self.h:
            return [self.w - 1, d + 1 - self.w]
        elif d < self.w * 2 + self.h - 2:
            return [self.w * 2 + self.h - 3 - d, self.h - 1]
        else:
            return [0, self.cycle - d]

    def getDir(self) -> str:
        if self.acc == 0:
            return 'East'
        d = self.acc % self.cycle
        # E : [1, w)
        # N : [w, w + h)
        # W : [w + h, w + h + w)
        # S : [w + h + w, w + h + w + h)
        if 1 <= d < self.w:
            return 'East'
        elif self.w <= d < self.w - 1 + self.h:
            return 'North'
        elif self.w - 1 + self.h <= d < 2 * self.w + self.h - 2:
            return 'West'
        else:
            return 'South'

# Your Robot object will be instantiated and called as such:
# obj = Robot(width, height)
# obj.step(num)
# param_2 = obj.getPos()
# param_3 = obj.getDir()
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            command = lines[0].strip('[').strip(']').strip('"').split('","')
            parameter = [list(map(int, (p.split(',')))) if p else [] for p in lines[1][2:-2].split('],[')]
            dataset.append((command, parameter))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    for command, parameter in dataset:
        for c, p in zip(command, parameter):
            if c == 'Robot':
                R = Robot(p[0],p[1])
            elif c == 'step':
                R.step(p[0])
            elif c == 'getPos':
                print(R.getPos(), end = ' ')
            else:
                print(R.getDir(), end = ' ')
        print()
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')