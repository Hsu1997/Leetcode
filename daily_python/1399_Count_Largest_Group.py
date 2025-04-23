import sys
import os
from collections import defaultdict

class Solution:
    def sumOfDigits(self, n) -> int:
        sum = 0
        while n > 0:
            sum += n % 10
            n //= 10
        return sum
    
    def countLargestGroup(self, n: int) -> int:
        count = defaultdict(int)
        for i in range(1, n+1):
            count[self.sumOfDigits(i)] += 1
        ans = 0
        maxGroupElements = 0
        for c in count.values():
            if c > maxGroupElements:
                maxGroupElements = c
                ans = 1
            elif c == maxGroupElements:
                ans += 1
            else:
                continue
        return ans
    
def readDataInFile(filename: str):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            dataset.append(n)
    return dataset

if __name__ == "__main__":
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    
    dataset = readDataInFile(filename)
    solution = Solution()
    results = []
    for n in dataset:
        results.append(solution.countLargestGroup(n))
    for index, result in enumerate(results):
        print(f'dataset {index+1} : {result}')