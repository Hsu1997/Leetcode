import os
import sys
from typing import List

class Node:
    def __init__(self, freq, prev = None, next = None):
        self.freq = freq
        self.prev = prev
        self.next = next
        self.keys = set()

class AllOne:
    def __init__(self):
        self.min_node = Node(0)
        self.max_node = Node(0)
        self.min_node.next = self.max_node
        self.max_node.prev = self.min_node
        self.map = {}

    def inc(self, key: str) -> None:
        if key in self.map:
            node = self.map[key]
            freq = node.freq
            node.keys.remove(key)
            if node.next == self.max_node or node.next.freq != node.freq + 1:
                next_node = Node(freq+1, node, node.next)
                node.next.prev = next_node
                node.next = next_node
            else:
                next_node = node.next
            next_node.keys.add(key)
            self.map[key] = next_node
            if not node.keys:
                node.prev.next = node.next
                node.next.prev = node.prev
                del node
        else:
            if self.min_node.next == self.max_node or self.min_node.next.freq != 1:
                next_node = Node(1, self.min_node, self.min_node.next)
                self.min_node.next.prev = next_node
                self.min_node.next = next_node
            else:
                next_node = self.min_node.next
            next_node.keys.add(key)
            self.map[key] = next_node

    def dec(self, key: str) -> None:
        node = self.map[key]
        freq = node.freq
        node.keys.remove(key)
        if freq == 1:
            del self.map[key]
        else:
            if node.prev == self.min_node or node.prev.freq != freq - 1:
                prev_node = Node(freq-1, node.prev, node)
                node.prev.next = prev_node
                node.prev = prev_node
            else:
                prev_node = node.prev
            prev_node.keys.add(key)
            self.map[key] = prev_node
        if not node.keys:
            node.prev.next = node.next
            node.next.prev = node.prev
            del node


    def getMaxKey(self) -> str:
        if self.max_node.prev == self.min_node:
            return ""
        else:
            return next(iter(self.max_node.prev.keys))

    def getMinKey(self) -> str:
        if self.min_node.next == self.max_node:
            return ""
        else:
            return next(iter(self.min_node.next.keys))
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            operation = list(lines[0][2:-2].split('","'))
            parameter = [p[1:-1] if p else "" for p in lines[1][2:-2].split('],[')]
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
        # print(operation)
        # print(parameter)
        result = []
        for op, pa in zip(operation, parameter):
            if op == "AllOne":
                solution = AllOne()
            elif op == "inc":
                solution.inc(pa)
            elif op == "dec":
                solution.dec(pa)
            elif op == "getMaxKey":
                result.append(solution.getMaxKey())
            elif op == "getMinKey":
                result.append(solution.getMinKey())
            else:
                print("Error")
        results.append(result)
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')