import os
import sys

class Fancy:
    def __init__(self):
        self.mod = int(10**9 + 7)
        self.nums = []
        self.a = 0
        self.m = 1

    def append(self, val: int) -> None:
        self.nums.append((val - self.a + self.mod) * self.pow(self.m, self.mod - 2) % self.mod)

    def addAll(self, inc: int) -> None:
        self.a = (self.a + inc) % self.mod

    def multAll(self, m: int) -> None:
        self.a = (self.a * m) % self.mod
        self.m = (self.m * m) % self.mod

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.nums):
            return -1
        return (self.m * self.nums[idx] + self.a) % self.mod
    
    def pow(self, base, power) -> int:
        res = 1
        while power:
            if power % 2 == 1:
                res = res * base % self.mod
            base = base * base % self.mod
            power //= 2
        return res

# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            operations = lines[0][2:-2].split('","')
            parameters = list(map(int, lines[1][5:-2].split('],[')))
            dataset.append((operations, parameters))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    for operations, parameters in dataset:
        result = []
        F = Fancy()
        for op, pa in zip(operations[1:], parameters):
            if op == 'append':
                F.append(pa)
            elif op == 'addAll':
                F.addAll(pa)
            elif op == 'multAll':
                F.multAll(pa)
            else:
                result.append(F.getIndex(pa))
        results.append(result)
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')