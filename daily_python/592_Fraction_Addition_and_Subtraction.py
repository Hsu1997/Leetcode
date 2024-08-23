import os
import sys

class Solution:
    def gcd(self, a, b)-> int:
        if b == 0:
            return a
        return self.gcd(b, a % b)
    
    def fractionAddition(self, expression: str) -> str:
        if expression[0] != '-':
            expression = '+' + expression
        index = 0
        s = len(expression)
        numerator = 0
        denominator = 1
        while(index < s):
            signal = 1 if expression[index] == '+' else -1
            index += 1
            curr_numerator = 0
            while(index < s and expression[index].isdigit()):
                curr_numerator = curr_numerator * 10 + int(expression[index])
                index += 1
            curr_numerator *= signal
            index += 1
            curr_denominator = 0
            while(index < s and expression[index].isdigit()):
                curr_denominator = curr_denominator * 10 + int(expression[index])
                index += 1
            # print(f'{curr_numerator} / {curr_denominator}')
            numerator = numerator * curr_denominator + curr_numerator * denominator
            denominator *= curr_denominator
            common_factor = self.gcd(numerator, denominator)
            numerator //= common_factor
            denominator //= common_factor
        return str(numerator) + '/' + str(denominator)
        
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            expression = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(expression)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for expression in dataset:
        results.append(solution.fractionAddition(expression))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')