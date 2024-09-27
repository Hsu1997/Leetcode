import os
import sys
from sortedcontainers import SortedDict

class MyCalendarTwo:
    def __init__(self):
        self.timeline = SortedDict()

    def book(self, start: int, end: int) -> bool:
        self.timeline[start] = self.timeline.get(start, 0) + 1
        self.timeline[end] = self.timeline.get(end, 0) - 1
        event = 0
        for time, count in self.timeline.items():
            event += count
            if event >= 3:
                self.timeline[start] -= 1
                self.timeline[end] += 1
                return False
        return True

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            event = [list(map(int, i.split(','))) for i in lines[0][2:-2].split('],[')]
            dataset.append(event)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    for sublist in dataset:
        solution = MyCalendarTwo()
        results.append([])
        for start, end in sublist:
            results[-1].append(solution.book(start, end))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)