import os
import sys
from typing import List

class Solution:
    def combination(self, n: int, m: int, l: int) -> int:
        m = min(m, n - m)
        res = 1
        for i in range(m):
            res = res * (n - i) // (i + 1)
            if res > l:
                return l + 1
        return res
    def permutation(self, cnt: List[int], total: int, l: int) -> int:
        p = 1
        for i in range(26):
            if cnt[i] == 0:
                continue
            p = p * self.combination(total, cnt[i], l)
            if p > l:
                return l + 1
            total -= cnt[i]
        return p
    def smallestPalindrome(self, s: str, k: int) -> str:
        n = len(s)
        cnt = [0] * 26
        for i in range(n // 2):
            cnt[ord(s[i]) - ord('a')] += 1
        if self.permutation(cnt, n // 2, k) < k:
            return ''
        left = []
        for i in range(n // 2):
            for c in range(26):
                if cnt[c] == 0:
                    continue
                curr = chr(ord('a') + c)
                cnt[c] -= 1
                p = self.permutation(cnt, n // 2 - 1 - i, k)
                if p < k:
                    k -= p
                    cnt[c] += 1
                else:
                    left.append(curr)
                    break
        mid = '' if n % 2 == 0 else s[n // 2]
        right = left[::-1]
        return ''.join(left) + mid + ''.join(right)
        
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((s, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, k in dataset:
        results.append(solution.smallestPalindrome(s, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')