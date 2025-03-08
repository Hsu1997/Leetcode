import os
import sys
from typing import List

class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        isPrime = [1] * (right + 1)
        isPrime[0] = 0
        isPrime[1] = 0
        idx = 2
        while idx * idx <= right:
            if isPrime[idx] == 1:
                for multiple in range(idx*idx, right+1, idx):
                    isPrime[multiple] = 0
            idx += 1
        prime = [num for num in range(left, right+1) if isPrime[num]]
        
        if len(prime) < 2:
            return (-1, -1)
        diff = float('inf')
        for i in range(1, len(prime)):
            if prime[i] - prime[i-1] < diff:
                diff = prime[i] - prime[i-1]
                ans = (prime[i-1], prime[i])
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            left = int(lines[0].split('=')[1].strip()[:-1])
            right = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((left, right))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for left, right in dataset:
        results.append(solution.closestPrimes(left, right))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')