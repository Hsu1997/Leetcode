import sys
import os
from typing import List

class Solution:
    def numTeams(self, rating: List[int]) -> int:
        max_element = max(rating)
        left_BIT = [0] * (max_element+1)
        right_BIT = [0] * (max_element+1)
        for num in rating:
            self.update(right_BIT, num, 1)
        ans = 0
        for num in rating:
            self.update(right_BIT, num, -1)
            left_smaller = self.query_range(left_BIT, 1, num-1)
            left_larger = self.query_range(left_BIT, num+1, max_element)
            right_smaller = self.query_range(right_BIT, 1, num-1)
            right_larger = self.query_range(right_BIT, num+1, max_element)
            ans += left_smaller * right_larger + left_larger * right_smaller
            self.update(left_BIT, num, 1)
        return ans
    
    def update(self, BIT: List[int], index: int, val: int) -> None:
        while(index < len(BIT)):
            BIT[index] += val
            index += index & (-index)
    def query(self, BIT: List[int], index: int)-> int:
        ans = 0
        while(index):
            ans += BIT[index]
            index -= index & (-index)
        return ans
    def query_range(self, BIT: List[int], left: int, right: int) -> int:
        return self.query(BIT, right) - self.query(BIT, left-1)

def readDataInFile(filename: str):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        lines = content.split('\n')
        for data in lines:
            data = list(map(int,(data.split('=')[1].strip().strip('{};').split(','))))
            dataset.append(data)
    return dataset

if __name__ == "__main__":
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    
    dataset = readDataInFile(filename)
    # print(dataset)
    solution = Solution()
    results = []
    for data in dataset:
        results.append(solution.numTeams(data))

    for index, result in enumerate(results):
        print(f'dataset {index+1} : {result}')