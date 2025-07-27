import os
import sys
from typing import List

class Solution:
    def maxSubarrays(self, n: int, conflictingPairs: List[List[int]]) -> int:
        Min1 = [n+1] * (n+2)
        Min2 = [n+1] * (n+2)
        for conflict in conflictingPairs:
            a = min(conflict[0], conflict[1])
            b = max(conflict[0], conflict[1])
            if b < Min1[a]:
                Min2[a] = Min1[a]
                Min1[a] = b
            elif b < Min2[a]:
                Min2[a] = b
        res = 0
        smallest_conflict_index = n
        second_smallest_conflict_range = n + 1
        remove_one_conflict_starting_from_added_subarrays = [0] * (n + 1)
        for i in range(n, 0, -1):
            if Min1[i] < Min1[smallest_conflict_index]:
                second_smallest_conflict_range = Min1[smallest_conflict_index]
                smallest_conflict_index = i
            else:
                second_smallest_conflict_range = min(second_smallest_conflict_range, Min1[i])
            res += Min1[smallest_conflict_index] - i
            remove_one_conflict_starting_from_added_subarrays[smallest_conflict_index] += min(Min2[smallest_conflict_index], second_smallest_conflict_range) - Min1[smallest_conflict_index]
        return res + max(remove_one_conflict_starting_from_added_subarrays)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            conflictingPairs = [list(map(int, conflict.split(','))) for conflict in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((n, conflictingPairs))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, conflictingPairs in dataset:
        results.append(solution.maxSubarrays(n, conflictingPairs))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')