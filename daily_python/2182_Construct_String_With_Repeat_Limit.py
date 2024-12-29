import os
import sys

class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        freq = [0] * 26
        ans = []
        for ch in s:
            freq[ord(ch) - ord('a')] += 1
        curr_idx = 25
        while curr_idx >= 0:
            if freq[curr_idx] == 0:
                curr_idx -= 1
                continue
            used = min(freq[curr_idx], repeatLimit)
            ans.append(chr(ord('a') + curr_idx) * used)
            freq[curr_idx] -= used
            if freq[curr_idx]:
                next_idx = curr_idx - 1
                while next_idx >= 0 and freq[next_idx] == 0:
                    next_idx -= 1
                if next_idx == -1:
                    break
                ans.append(chr(ord('a') + next_idx))
                freq[next_idx] -= 1
        return "".join(ans)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            repeatLimit = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((s, repeatLimit))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, repeatLimit in dataset:
        results.append(solution.repeatLimitedString(s, repeatLimit))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')