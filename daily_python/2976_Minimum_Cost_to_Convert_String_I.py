from typing import List
import os
import sys

class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        path = [[float('INF')] * 26 for _ in range(26)]
        for i in range(len(cost)):
            start = ord(original[i]) - ord('a')
            end = ord(changed[i]) - ord('a')
            path[start][end] = min(path[start][end], cost[i])
        path = self.floyd(path)
        ans = 0
        for source_char, target_char in zip(source, target):
            if source_char == target_char:
                continue
            source_char = ord(source_char) - ord('a')
            target_char = ord(target_char) - ord('a')
            if (path[source_char][target_char] == float('INF')):
                return -1
            ans += path[source_char][target_char]
        return ans

    def floyd(self, path: List[List[float]]) -> List[List[float]]:
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    path[i][j] = min(path[i][j], path[i][k] + path[k][j])
        return path

def readDataFromFile(filename: str):
    data = []
    with open(filename, 'r') as file:
        context = file.read().strip()
        blocks = context.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            source = lines[0].split('=')[1].strip().strip('"')
            target = lines[1].split('=')[1].strip().strip('"')
            original = lines[2].split('=')[1].strip().strip('{}').replace("'", "").replace('"', "").split(',')
            changed = lines[3].split('=')[1].strip().strip('{}').replace("'", "").replace('"', "").split(',')
            cost = list(map(int, lines[4].split('=')[1].strip().strip('{}').split(',')))
            data.append((source, target, original, changed, cost))
    return data

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        currfile = os.path.basename(__file__)
        filename = os.path.splitext(currfile)[0] + '.txt'
    else:
        filename = sys.argv[1]
    print(filename)
    data = readDataFromFile(filename)
    solution = Solution()
    results = []
    for source, target, original, changed, cost in data:
        results.append(solution.minimumCost(source, target, original, changed, cost))
    for index, result in enumerate(results):
        print(f"Dataset {index+1} : {result}")