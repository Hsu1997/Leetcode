import os
import sys

class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        cnt_y = customers.count('Y')
        cnt_n = 0
        ans = -1
        min_penalty = n
        for idx in range(n):
            if cnt_y + cnt_n < min_penalty:
                min_penalty = cnt_y + cnt_n
                ans = idx
            cnt_y -= (customers[idx] == 'Y')
            cnt_n += (customers[idx] == 'N')
        if cnt_n < min_penalty:
            return n
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            customers = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(customers)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for customers in dataset:
        results.append(solution.bestClosingTime(customers))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    