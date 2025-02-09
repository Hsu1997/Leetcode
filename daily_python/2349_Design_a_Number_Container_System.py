import os
import sys
import heapq
from typing import List
from collections import defaultdict

class NumberContainers:
    def __init__(self):
        self.number_to_index = defaultdict(list)
        self.index_to_number = {}

    def change(self, index: int, number: int) -> None:
        self.index_to_number[index] = number
        heapq.heappush(self.number_to_index[number], index)

    def find(self, number: int) -> int:
        while self.number_to_index[number]:
            index = self.number_to_index[number][0]
            if number == self.index_to_number[index]:
                return index
            else:
                heapq.heappop(self.number_to_index[number])
                if not self.number_to_index[number]:
                    del self.number_to_index[number]
        return -1


def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            operation = lines[0][2:-2].split('", "')
            parameter = [list(map(int, parameters.split(', '))) if parameters else [] for parameters in lines[1][2:-2].split('], [')]
            dataset.append((operation, parameter))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    for operation, parameter in dataset:
        solution = NumberContainers()
        curr_result = []
        for op, inp in zip(operation, parameter):
            if op == "NumberContainers":
                continue
            elif op == "change":
                solution.change(inp[0], inp[1])
            elif op == "find":
                curr_result.append(solution.find(inp[0]))
            else:
                print("Error")
        results.append(curr_result)
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')