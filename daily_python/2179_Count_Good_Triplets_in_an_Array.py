import sys
import os
from typing import List

class BinaryIndexTree:
    def __init__(self, n: int):
        self.tree = [0] * (n + 1)
    
    def update(self, pos: int, val: int) -> None:
        pos += 1
        while pos < len(self.tree):
            self.tree[pos] += val
            pos += pos & (-pos)
        return
    
    def query(self, pos: int) -> int:
        pos += 1
        ans = 0
        while pos > 0:
            ans += self.tree[pos]
            pos -= pos & (-pos)
        return ans
    
class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        same_elements_count_after_nums1 = [0] * n
        same_elements_count_before_nums1 = [0] * n
        pos2 = [-1] * n
        for i in range(n):
            pos2[nums2[i]] = i
        BIT1 = BinaryIndexTree(n)
        for i in range(n-1, -1, -1):
            same_elements_count_after_nums1[i] = n - 1 - i - BIT1.query(pos2[nums1[i]])
            BIT1.update(pos2[nums1[i]], 1)
        # print(same_elements_count_after_nums1)
        BIT2 = BinaryIndexTree(n)
        for i in range(n):
            same_elements_count_before_nums1[i] = BIT2.query(pos2[nums1[i]])
            BIT2.update(pos2[nums1[i]], 1)
        # print(same_elements_count_before_nums1)
        ans = 0
        for i in range(n):
            ans += same_elements_count_before_nums1[i] * same_elements_count_after_nums1[i]
        return ans
    
def readData(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums1 = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            nums2 = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((nums1, nums2))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readData(filename)
    results = []
    solution = Solution()
    for nums1, nums2 in dataset:
        results.append(solution.goodTriplets(nums1, nums2))
    for index, result in enumerate(results):
        print(f'Dataset {index+1} : {result}')
