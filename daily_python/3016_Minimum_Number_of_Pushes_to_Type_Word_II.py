import sys
import os
from typing import List
from collections import Counter
import heapq

class Solution:
    def minimumPushes(self, word: str) -> int:
        frequency_map = Counter(word)
        frequency = [-freq for freq in frequency_map.values()]
        heapq.heapify(frequency)
        ans = 0
        index = 0
        while frequency:
            ans += (index // 8 + 1) * -heapq.heappop(frequency)
            index += 1
        return ans

        # frequency = [0] * 26
        # for c in word:
        #     frequency[ord(c) - ord('a')] += 1
        # frequency.sort(reverse=True)
        # ans = 0
        # for i in range(26):
        #     if frequency[i] == 0:
        #         return ans
        #     else:
        #         ans += (i // 8 + 1 ) * frequency[i]
        # return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        data = content.split('\n')
        for ex in data:
            ex = ex.split('=')[1].strip().strip(';').strip('\"')
            dataset.append(ex)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    results = []
    solution = Solution()
    dataset = readDataSet(filename)
    for example in dataset:
        results.append(solution.minimumPushes(example))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')