import os
import sys

class CustomStack:
    def __init__(self, maxSize: int):
        self.stack = []
        self.limit = maxSize

    def push(self, x: int) -> None:
        if len(self.stack) < self.limit:
            self.stack.append(x)

    def pop(self) -> int:
        if not self.stack:
            return -1
        return self.stack.pop()

    def increment(self, k: int, val: int) -> None:
        for i in range(min(len(self.stack), k)):
            self.stack[i] += val

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            command = lines[0][2:-2].split('","')
            val = lines[1][2:-2].split('],[')
            commands = []
            for c, v in zip(command, val):
                commands.append((c, v))
            dataset.append(commands)
    print(dataset)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    for subproblem in dataset:
        result = []
        for command, value in subproblem:
            if command == 'CustomStack':
                stk = CustomStack(int(value))
            elif command == 'push':
                stk.push(int(value))
            elif command == 'pop':
                result.append(stk.pop())
            elif command == 'increment':
                val = list(map(int, value.split(',')))
                stk.increment(val[0], val[1])
        results.append(result)
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : {result}')