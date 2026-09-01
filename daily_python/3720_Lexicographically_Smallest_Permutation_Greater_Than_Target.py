import os
import sys
from typing import List

class Solution:
    def remainGreater(self, cnt, target, idx) -> bool:
        for c in range(25, -1, -1):
            for _ in range(cnt[c]):
                if idx >= len(target):
                    return False
                target_c = ord(target[idx]) - ord('a')
                if c > target_c:
                    return True
                if c < target_c:
                    return False
                idx += 1
        return False
    
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        n = len(s)
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - ord('a')] += 1
        res = []
        for i in range(n):
            curr = ord(target[i]) - ord('a')
            if cnt[curr]:
                cnt[curr] -= 1
                if self.remainGreater(cnt, target, i + 1):
                    res.append(chr(ord('a') + curr))
                    continue
                cnt[curr] += 1
            for c in range(curr + 1, 26):
                if cnt[c]:
                    cnt[c] -= 1
                    res.append(chr(ord('a') + c))
                    for j in range(26):
                        while cnt[j]:
                            res.append(chr(ord('a') + j))
                            cnt[j] -= 1
                    return "".join(res)
            return ""
        return ""

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            target = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((s, target))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, target in dataset:
        results.append(solution.lexGreaterPermutation(s, target))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')