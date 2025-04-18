import os
import sys

class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        prev = self.countAndSay(n-1)
        last = prev[0]
        count = 0
        ans = []
        for i in range(len(prev)):
            if prev[i] == last:
                count += 1
            else:
                ans.append(str(count))
                ans.append(last)
                count = 1
                last = prev[i]
        ans.append(str(count))
        ans.append(last)
        return "".join(ans)

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
        results.append(solution.countAndSay(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
