import os
import sys
from typing import List

class Solution:
    def countSeniors(self, details: List[str]) -> int:
        ans = 0
        for passenger in details:
            if int(passenger[11:13]) > 60:
                ans += 1
        return ans
        
def readData(filename):
    dataset = []
    with open(filename, 'r') as file:
        context = file.read().strip()
        datas = context.split('\n')
        for lines in datas:
            line = lines.split('=')[1].strip()[1:-2].replace('\"',"")
            data = line.split(',')
            dataset.append(data)
    return dataset


if __name__ == '__main__':
    if (len(sys.argv)) == 1:
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readData(filename)
    solution = Solution()
    results = []
    for data in dataset:
        results.append(solution.countSeniors(data))
    for index, result in enumerate(results):
        print(f'data {index+1} : {result}')
