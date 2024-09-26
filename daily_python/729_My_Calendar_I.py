import os
import sys
from sortedcontainers import SortedList

class MyCalendar:
    def __init__(self):
        self.calendar = SortedList()

    def book(self, start: int, end: int) -> bool:
        idx = self.calendar.bisect_right((start, end))
        if idx - 1 >= 0 and self.calendar[idx - 1][1] > start:
            return False
        if idx < len(self.calendar) and self.calendar[idx][0] < end:
            return False
        self.calendar.add((start, end))
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
        solution = MyCalendar()
        results.append([])
        for start, end in sublist:
            results[-1].append(solution.book(start, end))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)