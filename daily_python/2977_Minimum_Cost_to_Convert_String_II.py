from typing import List
import os
import sys

class Node:
    def __init__(self):
        self.child = [None] * 26
        self.idx = -1

class Trie:
    def __init__(self):
        self.root = Node()

    def add(self, s: str, i: int) -> None:
        r = self.root
        for c in s:
            v = ord(c) - ord('a')
            if r.child[v] is None:
                r.child[v] = Node()
            r = r.child[v]
        r.idx = i

class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        stringToIdx = {}
        T = Trie()
        idx = 0
        inf = 10 ** 30
        for s in original + changed:
            if s in stringToIdx:
                continue
            stringToIdx[s] = idx
            T.add(s, idx)
            idx += 1
        d = [[inf] * idx for _ in range(idx)]
        for i in range(idx):
            d[i][i] = 0
        for i in range(len(original)):
            u = stringToIdx[original[i]]
            v = stringToIdx[changed[i]]
            d[u][v] = min(d[u][v], cost[i])
        for k in range(idx):
            for i in range(idx):
                if d[i][k] >= inf:
                    continue
                for j in range(idx):
                    if d[k][j] >= inf:
                        continue
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j])
        n = len(source)
        dp = [inf] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            if dp[i-1] >= inf:
                continue
            if source[i-1] == target[i-1]:
                dp[i] = min(dp[i], dp[i-1])
            currS = T.root
            currT = T.root
            for j in range(i - 1, n):
                currS = currS.child[ord(source[j]) - ord('a')]
                currT = currT.child[ord(target[j]) - ord('a')]
                if currS is None or currT is None:
                    break
                if currS.idx != -1 and currT.idx != -1:
                    w = d[currS.idx][currT.idx]
                    if w < inf:
                        dp[j+1] = min(dp[j+1], dp[i-1] + w)
        return dp[n] if dp[n] < inf else -1

def readDataFromFile(filename: str):
    data = []
    with open(filename, 'r') as file:
        context = file.read().strip()
        blocks = context.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            source = lines[0].split('=')[1].strip()[:-1].strip('"')
            target = lines[1].split('=')[1].strip()[:-1].strip('"')
            original = lines[2].split('=')[1].strip()[2:-3].split('","')
            changed = lines[3].split('=')[1].strip()[2:-3].split('","')
            cost = list(map(int, lines[4].split('=')[1].strip()[1:-2].split(',')))
            data.append((source, target, original, changed, cost))
    return data

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        currfile = os.path.basename(__file__)
        filename = os.path.splitext(currfile)[0] + '.txt'
    else:
        filename = sys.argv[1]
    data = readDataFromFile(filename)
    solution = Solution()
    results = []
    for source, target, original, changed, cost in data:
        results.append(solution.minimumCost(source, target, original, changed, cost))
    for index, result in enumerate(results):
        print(f"Dataset {index+1} : {result}")