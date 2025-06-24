import os
import sys
from typing import List

class Solution:
    def kMirror(self, k: int, n: int) -> int:
        def is_palindrome(x: int) -> bool:
            d = list()
            while x:
                d.append(x % k)
                x //= k
            return d == d[::-1]
        left, count, ans = 1, 0, 0
        while count < n:
            right = left * 10
            for op in [0,1]:
                for i in range(left, right):
                    combined = i
                    x = i if op == 1 else i // 10
                    while x:
                        combined = combined * 10 + (x % 10)
                        x //= 10
                    if is_palindrome(combined):
                        ans += combined
                        count += 1
                        if count == n:
                            return ans
            left = right
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            k = int(lines[0].split('=')[1].strip()[:-1])
            n = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((k, n))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for k, n in dataset:
        results.append(solution.kMirror(k, n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')