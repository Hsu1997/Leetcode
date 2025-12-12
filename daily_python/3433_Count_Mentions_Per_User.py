import os
import sys
from typing import List

class Solution:
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        online = [0] * numberOfUsers
        ans = [0] * numberOfUsers
        events.sort(key=lambda e: (int(e[1]), e[0] == "MESSAGE"))
        for event in events:
            t = int(event[1])
            if event[0] == 'MESSAGE':
                if event[2] == 'ALL':
                    for i in range(numberOfUsers):
                        ans[i] += 1
                elif event[2] == 'HERE':
                    for i in range(numberOfUsers):
                        if online[i] <= t :
                            ans[i] += 1
                else:
                    for idx in event[2].split():
                        ans[int(idx[2:])] += 1
            else:
                online[int(event[2])] = t + 60
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            numberOfUsers = int(lines[0].split('=')[1].strip()[:-1])
            events = [list(event.split('","')) for event in lines[1].split('=')[1].strip()[3:-4].split('"},{"')]
            dataset.append((numberOfUsers, events))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for numberOfUsers, events in dataset:
        results.append(solution.countMentions(numberOfUsers, events))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')