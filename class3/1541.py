'''
1. take first number and add number before minus
2. if the minus sign has taken, add all the number with plus
3. repeat
'''

import sys

input = sys.stdin.readline
print = sys.stdout.write

number_sentence = input().rstrip()

min_result = 0
curr_number = 0
sign = 1

for letter in number_sentence:
    if '0' <= letter <= '9':
        curr_number = curr_number * 10 + ord(letter) - ord('0')
    else:
        min_result += curr_number * sign
        if letter == '-':
            sign = -1
        curr_number = 0

min_result += curr_number * sign

print(str(min_result))