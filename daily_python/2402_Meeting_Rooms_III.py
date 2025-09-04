import os
import sys
import heapq
from typing import List

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        freeRooms = [i for i in range(n)]
        usedRooms = []
        roomcnt = [0] * n
        heapq.heapify(freeRooms)

        for meeting in meetings:
            start = meeting[0]
            end = meeting[1]
            while usedRooms and usedRooms[0][0] <= start:
                heapq.heappush(freeRooms, usedRooms[0][1])
                heapq.heappop(usedRooms)
            if freeRooms:
                heapq.heappush(usedRooms, (end, freeRooms[0]))
                roomcnt[freeRooms[0]] += 1
                heapq.heappop(freeRooms)
            else:
                curr_time, curr_room = heapq.heappop(usedRooms)
                heapq.heappush(usedRooms, (curr_time + (end - start), curr_room))
                roomcnt[curr_room] += 1
        ans = 0
        for i in range(1, n):
            if roomcnt[i] > roomcnt[ans]:
                ans = i
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            meetings = [list(map(int, meeting.split(','))) for meeting in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((n, meetings))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, meetings in dataset:
        results.append(solution.mostBooked(n, meetings))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')