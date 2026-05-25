import os
import sys
from typing import List
from collections import deque

class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        que = deque([0])
        slot = deque([i for i in range(1, n) if s[i] == '0'])
        while que:
            curr = que.popleft()
            if curr == n - 1:
                return True
            while slot and curr + maxJump >= slot[0]:
                if slot[0] >= curr + minJump:
                    que.append(slot[0])
                slot.popleft()
        return False

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            minJump = int(lines[1].split('=')[1].strip()[:-1])
            maxJump = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((s, minJump, maxJump))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, minJump, maxJump in dataset:
        results.append(solution.canReach(s, minJump, maxJump))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')