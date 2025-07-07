import os
import sys
from typing import List

class FindSumPairs:
    def __init__(self, nums1: List[int], nums2: List[int]):
        self.cnt = {}
        self.nums1 = nums1
        self.nums2 = nums2
        for i in nums2:
            self.cnt[i] = self.cnt.get(i, 0) + 1

    def add(self, index: int, val: int) -> None:
        self.cnt[self.nums2[index]] -= 1
        self.nums2[index] += val
        self.cnt[self.nums2[index]] = self.cnt.get(self.nums2[index], 0) + 1

    def count(self, tot: int) -> int:
        ans = 0
        for i in self.nums1:
            ans += self.cnt.get(tot - i, 0)
        return ans

# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            operation = lines[0][2:-2].split('", "')
            para = lines[1][3:-2].split('], [')
            init = [list(map(int, para[0].split(','))), list(map(int, para[1][:-1].split(',')))]
            parameter = [init] + [list(map(int, arr.split(','))) for arr in para[2:]]
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
        nums1 = parameter[0][0]
        nums2 = parameter[0][1]
        solution = FindSumPairs(nums1, nums2)
        result = []
        for op, para in zip(operation[1:], parameter[1:]):
            if op == 'count':
                result.append(solution.count(para[0]))
            else:
                solution.add(para[0], para[1])
        results.append(result)
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')