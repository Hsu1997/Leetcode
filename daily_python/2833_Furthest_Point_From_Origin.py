import os
import sys

class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        return moves.count('_') + abs(moves.count('L') - moves.count('R'))
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            moves= lines[0].split('=')[1].strip()[1:-2]
            dataset.append(moves)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for moves in dataset:
        results.append(solution.furthestDistanceFromOrigin(moves))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')