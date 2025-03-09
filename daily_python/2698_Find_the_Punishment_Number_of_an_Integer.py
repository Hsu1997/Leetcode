import os
import sys
from queue import Queue

class Solution:
    def punishmentNumber(self, n: int) -> int:
        punishment = 0
        for num in range(1, n+1):
            if self.isPunishmentNumber(num * num, num):
                punishment += num * num
        return punishment
    
    def isPunishmentNumber(self, num, target):
        if num == target:
            return True
        if num == 0 or target < 0:
            return False
        return self.isPunishmentNumber(num // 10, target - num % 10) or self.isPunishmentNumber(num // 100, target - num % 100) or self.isPunishmentNumber(num // 1000, target - num % 1000)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            dataset.append(n)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n in dataset:
        results.append(solution.punishmentNumber(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')