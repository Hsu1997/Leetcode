import os
import sys
from collections import defaultdict

class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        char_to_index = defaultdict(lambda: 0)
        char_to_index['a'] = 1
        char_to_index['e'] = 2
        char_to_index['i'] = 4
        char_to_index['o'] = 8
        char_to_index['u'] = 16
        first_time_seen = {0: -1}
        prefix = 0
        ans = 0
        for index, c in enumerate(s):
            prefix ^= char_to_index[c]
            if prefix not in first_time_seen:
                first_time_seen[prefix] = index
            ans = max(ans, index - first_time_seen[prefix])
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[:-1].strip('"')
            dataset.append(s)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s in dataset:
        results.append(solution.findTheLongestSubstring(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}' )