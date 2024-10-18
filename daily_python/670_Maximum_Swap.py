import os
import sys

class Solution:
    def maximumSwap(self, num: int) -> int:
        num_str = list(str(num))
        n = len(num_str)
        last_seen = [-1] * 10
        for i in range(n):
            last_seen[int(num_str[i])] = i
        for i in range(n):
            for d in range(9, int(num_str[i]), -1):
                if last_seen[d] > i:
                    num_str[i], num_str[last_seen[d]] = (num_str[last_seen[d]], num_str[i])
                    
                    num_str = "".join(num_str)
                    
                    return int(num_str)
                    
        return num
    
# class Solution:
#     def maximumSwap(self, num: int) -> int:
#         num_str = str(num)
#         n = len(num_str)
#         last_seen = [-1] * 10  # Store the last occurrence of each digit

#         # Record the last occurrence of each digit
#         for i in range(n):
#             last_seen[int(num_str[i])] = i

#         # Traverse the string to find the first digit that can be swapped with a larger one
#         for i in range(n):
#             for d in range(9, int(num_str[i]), -1):
#                 if last_seen[d] > i:
#                     # Perform the swap
#                     num_str = list(num_str)
                    # num_str[i], num_str[last_seen[d]] = (num_str[last_seen[d]],num_str[i])
                    # num_str = "".join(num_str)
                    # return int(num_str)

#         return num  # Return the original number if no swap can maximize it
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            num = int(lines[0].split('=')[1].strip()[:-1])
            dataset.append(num)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for num in dataset:
        results.append(solution.maximumSwap(num))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')