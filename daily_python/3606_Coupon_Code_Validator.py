import os
import sys
from typing import List

class Solution:
    def valid(self, s: str) -> bool:
        for c in s:
            if not c.isalnum() and c != '_':
                return False
        return True

    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        order = ["electronics", "grocery", "pharmacy", "restaurant"]
        n = len(code)
        ans = []
        for o in order:
            temp = []
            for i in range(n):
                if not isActive[i] or code[i] == '' or businessLine[i] != o:
                    continue
                if self.valid(code[i]):
                    temp.append(code[i])
            temp.sort()
            ans.extend(temp)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            code = lines[0].split('=')[1].strip()[2:-3].split('","')
            businessLine = lines[1].split('=')[1].strip()[2:-3].split('","')
            isActive = [True if a == 'true' else False for a in lines[2].split('=')[1].strip()[1:-2].split(',')]
            dataset.append((code, businessLine, isActive))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for code, businessLine, isActive in dataset:
        results.append(solution.validateCoupons(code, businessLine, isActive))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')