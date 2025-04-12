import os
import sys
import heapq
from typing import List
from collections import defaultdict
from math import factorial

class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        palindrome = set()
        for i in range(int(10 ** ((n + 1) // 2 - 1)), int(10 ** ((n + 1) // 2))):
            head = str(i)
            tail = head[::-1]
            if n % 2 == 1:
                head = head[:-1]
            head += tail
            num = int(head)
            if num % k == 0:
                head = "".join(sorted(head))
                palindrome.add(head)
        # print(palindrome)
        fac = [factorial(i) for i in range(n+1)]
        ans = 0
        for s in palindrome:
            cnt = [0] * 10
            for c in s:
                cnt[int(c)] += 1
            total = (n - cnt[0]) * fac[n-1]
            for x in cnt:
                total //= fac[x]
            ans += total
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((n, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, k in dataset:
        results.append(solution.countGoodIntegers(n, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    