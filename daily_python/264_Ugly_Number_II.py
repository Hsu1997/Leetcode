import os
import sys

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        if n == 1:
            return 1
        two = [2]
        three = [3]
        five = [5]
        for _ in range(n - 2):
            temp = min(two[0], three[0], five[0])
            if two[0] == temp:
                two.pop(0)
            if three[0] == temp:
                three.pop(0)
            if five[0] == temp:
                five.pop(0)
            two.append(temp * 2)
            three.append(temp * 3)
            five.append(temp * 5)
        return min(two[0], three[0], five[0])
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            dataset.append(n)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n in dataset:
        results.append(solution.nthUglyNumber(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')