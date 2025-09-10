import os
import sys
from typing import List

class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        mod = (int)(1e9 + 7)
        new_know = [0] * (n + forget)
        new_know[0] = 1
        acc_share = 0
        acc_know = 1
        for day in range(1, n):
            if day - delay >= 0:
                acc_share = (acc_share + new_know[day - delay]) % mod
            if day - forget >= 0:
                acc_share = (acc_share - new_know[day - forget]) % mod
            new_know[day] = acc_share
            acc_know = (acc_know + new_know[day]) % mod
            if day - forget >= 0:
                acc_know = (acc_know - new_know[day - forget]) % mod
        return acc_know
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            delay = int(lines[1].split('=')[1].strip()[:-1])
            forget = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((n, delay, forget))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, delay, forget in dataset:
        results.append(solution.peopleAwareOfSecret(n, delay, forget))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')