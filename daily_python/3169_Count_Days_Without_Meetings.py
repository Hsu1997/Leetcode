import os
import sys
from typing import List

class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        n = len(meetings)
        meetings.sort()
        end = 0
        ans = 0
        for curr_start, curr_end in meetings:
            if curr_start > end:
                ans += curr_start - end - 1
            end = max(end, curr_end)
        if days > end:
            ans += days - end
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')

            days = int(lines[0].split('=')[1].strip()[:-1])
            meetings = [list(map(int, meeting.split(','))) for meeting in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((days, meetings))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for days, meetings in dataset:
        results.append(solution.countDays(days, meetings))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')