import sys
import os

class Solution:
    number = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
    number_ten = ["", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
    number_teen = ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
    numeral = ["", " Thousand", " Million", " Billion"]

    def helper(self, num: int) -> str:
        ans = ""
        if num // 100:
            ans += self.number[num // 100] + " Hundred"
            num %= 100
        if num > 19:
            if ans:
                ans += " "
            ans += self.number_ten[num // 10]
            if num % 10:
                ans += " " + self.number[num % 10]
        elif num > 9:
            if ans:
                ans += " "
            ans += self.number_teen[num % 10]
        elif num > 0:
            if ans:
                ans += " "
            ans += self.number[int(num % 10)]
        return ans

    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"
        ans = ""
        index = 0
        while num > 0:
            part = num % 1000
            if part:
                pre_str = self.helper(part) + self.numeral[index]
                if ans:
                    ans = pre_str + " " + ans
                else:
                    ans = pre_str
            index += 1
            num //= 1000
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        data = content.split('\n')
        for line in data:
            line = line.split('=')[1].strip().strip(';')
            dataset.append(int(line))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    solution = Solution()
    results = []
    for num in dataset:
        results.append(solution.numberToWords(num))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')
    