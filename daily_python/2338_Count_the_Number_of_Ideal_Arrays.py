import os
import sys
from typing import List

class Solution:
    def BuildCTable(self, n: int, k: int, mod: int) -> None:
        self.c = [[0] * (k+1) for _ in range(n+1)]
        self.c[0][0] = 1
        for i in range(1, n+1):
            self.c[i][0] = 1
            for j in range(1, min(i, k) + 1):
                self.c[i][j] = (self.c[i-1][j-1] + self.c[i-1][j]) % mod
        return
    
    def BuildPowerOfFactor(self, n: int) -> None:
        self.power = [[] for _ in range(n+1)]
        greatestFactor = [0] * (n+1)
        for i in range(2, n+1):
            if greatestFactor[i] == 0:
                for j in range(i, n+1, i):
                    greatestFactor[j] = i
        for num in range(2, n+1):
            temp = num
            while temp > 1:
                factor = greatestFactor[temp]
                power = 0
                while temp % factor == 0:
                    temp //= factor
                    power += 1
                self.power[num].append(power)
        return
    
    def idealArrays(self, n: int, maxValue: int) -> int:
        mod = int(1e9+7)
        self.BuildCTable(n-1+14, 14, mod)
        self.BuildPowerOfFactor(maxValue)
        ans = 0
        for max_element in range(1, maxValue + 1):
            mul = 1
            for p in self.power[max_element]:
                mul = (mul * self.c[n-1+p][p]) % mod
            ans = (ans + mul) % mod
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            maxValue = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((n, maxValue))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, maxValue in dataset:
        results.append(solution.idealArrays(n, maxValue))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')