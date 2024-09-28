import os
import sys

class Node:
    def __init__(self, val, prev = None, next = None):
        self.prev = prev
        self.next = next
        self.val = val


class MyCircularDeque:
    def __init__(self, k: int):
        self.head = None
        self.rear = None
        self.size = 0
        self.capacity = k

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        new_Node = Node(value)
        if self.isEmpty():
            self.head = self.rear = new_Node
        else:
            new_Node.next = self.head
            self.head.prev = new_Node
            self.head = new_Node
        self.size += 1
        self.capacity -= 1
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        new_Node = Node(value)
        if self.isEmpty():
            self.head = self.rear = new_Node
        else:
            new_Node.prev = self.rear
            self.rear.next = new_Node
            self.rear = new_Node
        self.size += 1
        self.capacity -= 1
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        if self.size == 1:
            self.head = self.rear = None
        else:
            self.head = self.head.next
            self.head.prev = None
        self.size -= 1
        self.capacity += 1
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        if self.size == 1:
            self.head = self.rear = None
        else:
            self.rear = self.rear.prev
            self.rear.next = None
        self.size -= 1
        self.capacity += 1
        return True

    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.head.val

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        return self.rear.val

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.capacity == 0

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            command = lines[0][2:-2].split('","')
            parameter = lines[1][2:-2].split('],[')
            # print(command)
            # print(parameter)
            commands = []
            for c, p in zip(command, parameter):
                commands.append((c, int(p) if p is not '' else None))
            dataset.append(commands)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []

    for problem in dataset:
        result = []
        for command, param in problem:
            # print(command, param)
            if command == "MyCircularDeque":
                deque = MyCircularDeque(param)
            elif command == "insertFront":
                result.append(deque.insertFront(param))
            elif command == "insertLast":
                result.append(deque.insertLast(param))
            elif command == "deleteFront":
                result.append(deque.deleteFront())
            elif command == "deleteLast":
                result.append(deque.deleteLast())
            elif command == "getFront":
                result.append(deque.getFront())
            elif command == "getRear":
                result.append(deque.getRear())
            elif command == "isEmpty":
                result.append(deque.isEmpty())
            elif command == "isFull":
                result.append(deque.isFull())
        results.append(result)
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')