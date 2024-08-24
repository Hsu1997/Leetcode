import os
import sys

class Solution:
    def palindrome(self, n: int, odd: bool) -> int:
        ans = n
        if odd:
            n //= 10
        while n:
            ans = ans * 10 + n % 10
            n //= 10
        return ans
    
    def nearestPalindromic(self, n: str) -> str:
        candidate = []
        size = len(n)
        odd = size % 2
        half = int(n[:(size + 1) // 2])
        candidate.append(self.palindrome(half, odd))
        candidate.append(self.palindrome(half + 1, odd))
        candidate.append(self.palindrome(half - 1, odd))
        candidate.append(10 ** size + 1)
        candidate.append(10 ** (size - 1) - 1)
        diff = float('inf')
        ans = 10 ** size
        for c in candidate:
            # print(c, end = " ")
            if c == int(n):
                continue
            if abs(int(n) - c) < diff:
                diff = abs(int(n) - c)
                ans = c
            elif abs(int(n) - c) == diff:
                ans = min(ans, c)
        # print()
        return str(ans)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        context = file.read().strip()
        blocks = context.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(n)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    solution = Solution()
    results = []
    dataset = readDataSet(filename)
    for n in dataset:
        results.append(solution.nearestPalindromic(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')