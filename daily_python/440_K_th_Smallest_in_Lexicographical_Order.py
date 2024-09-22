import os
import sys

class Solution:
    def count_children(self, n: int, limit: int) -> int :
        steps = 0
        curr_children = 10
        n *= 10
        while n <= limit:
            steps += min(limit - n + 1, curr_children)
            curr_children *= 10
            n *= 10
        return steps

    def findKthNumber(self, n: int, k: int) -> int:
        curr = 1
        k -= 1
        while k > 0:
            children = self.count_children(curr, n)
            if children < k:
                k -= children
                curr += 1
            else:
                curr *= 10
            k -= 1
        return curr
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((n, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, k in dataset:
        results.append(solution.findKthNumber(n, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')