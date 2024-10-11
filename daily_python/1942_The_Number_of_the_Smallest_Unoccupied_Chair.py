import os
import sys
import heapq
from typing import List

class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        target_time = times[targetFriend][0]
        times.sort()
        chair = []
        occupied = []
        next = 0
        for start, leave in times:
            while occupied and start >= occupied[0][0]:
                heapq.heappush(chair, heapq.heappop(occupied)[1])
            if chair:
                taken_chair = heapq.heappop(chair)
            else:
                taken_chair = next
                next += 1
            if start == target_time:
                return taken_chair
            heapq.heappush(occupied, (leave, taken_chair))
        return -1
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            times = [list(map(int, i.split(','))) for i in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            targetFriend = int(lines[1].split('=')[1].strip()[:-1])
            print(times)
            dataset.append((times, targetFriend))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for times, targetFriend in dataset:
        results.append(solution.smallestChair(times, targetFriend))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')