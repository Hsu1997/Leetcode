import os
import sys
from typing import List

class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        n = len(players)
        m = len(trainers)
        j = 0
        ans = 0
        for i in range(n):
            while j < m and players[i] > trainers[j]:
                j += 1
            if j == m:
                break
            ans += 1
            j += 1
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            players = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            trainers = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((players, trainers))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for players, trainers in dataset:
        results.append(solution.matchPlayersAndTrainers(players, trainers))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')